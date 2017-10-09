#include "PlayState.h"
#include "PauseState.h"
#include "SoundManager.h"

void PlayState::init(SDL_Renderer* m_renderer) {
	SoundManager::Instance()->load("sounds/song.mp3", "background", SOUND_MUSIC);
	SoundManager::Instance()->load("sounds/ball_bounce.wav", "ballBounce", SOUND_FX);
	SoundManager::Instance()->load("sounds/ball_spawn.wav", "ballSpawn", SOUND_FX);
	SoundManager::Instance()->load("explosion.wav", "explosion", SOUND_FX);
	background.load(m_renderer);
	ball.load(m_renderer);
	player.load(m_renderer);
	for (int i = 0; i < Blocks::BLOCKS_COLUMNS * Blocks::BLOCKS_ROWS; i++) {
		blocksArr[i].load(m_renderer);
	}
	setBlocks();
	font.init();
	player.setLives(3);
}

void PlayState::close() {
	background.free();
	player.free();
	font.close("blocksText");
	font.close("lives");
}

void PlayState::handleEvents(Game* g, SDL_Event& e) {
	uint32_t delta = timer.tick();
	player.handleMovement(e, delta);
	ball.unlockBall(e);
	switch (e.key.keysym.sym) {
	case SDLK_ESCAPE:
		g->pushState(&PauseState::Instance());
	}
}

void PlayState::update() {
	ball.update();
	player.update();
	
	if (ball.isLocked()) {
		float paddleCenterX = player.getXPos() + player.rect.w / 2;
		ball.setXPos(paddleCenterX - ball.rect.w / 2);
		ball.setYPos(player.getYPos() - ball.rect.h);
	}
	else {
		ball.setYPos(ball.getYPos() + ball.getYVel());
		if (collider.RectsOverlap(ball.rect, player.rect)) {
			ball.setYPos(ball.getYPos() - 1);
			ball.setYPos(ball.getYPos() - ball.getYVel());
			ball.setYVel(ball.getYVel() * -1.0f);
		}
		else {
			for (int i = 0; i < Blocks::BLOCKS_COLUMNS * Blocks::BLOCKS_ROWS; i++) {
				if (blocksArr[i].isAlive() && collider.RectsOverlap(ball.rect, blocksArr[i].rect)) {
					ball.setYVel(ball.getYVel() * -1.0f);
					blocksArr[i].setAlive(false);
				}
			}
		}
		ball.setXPos(ball.getXPos() + ball.getXVel());
		if (ball.getYPos() > Game::GAME_AREA_Y2) {
			player.setLives(player.getLives() - 1);
		}
		/*
		if (collider.RectsOverlap(ball.rect, player.rect)) {
			ball.setXPos(ball.getXPos() - (rand() % 2));
			ball.setXPos(ball.getXPos() - ball.getXVel());
			ball.setXVel(ball.getXVel() * -1.0f);
		}
		*/
		/*
		else {
			for (int i = 0; i < Blocks::BLOCKS_COLUMNS * Blocks::BLOCKS_ROWS; i++) {
				ball.setXPos(ball.getXPos() + 1);
				ball.setXVel(ball.getXVel() * -1.0f);
			}
		}
		*/
	}
}

void PlayState::render(SDL_Renderer* m_renderer) {
	SDL_Color textColor = { 255, 255, 255 };

	char blocksText[64];
	char livesText[64];
	sprintf_s(blocksText, "Blocks: %d", numBlocksLeft());
	sprintf_s(livesText, "Lives: %d", player.getLives());
	font.load("lives", livesText, textColor, m_renderer);
	font.load("blocksText", blocksText, textColor, m_renderer);

	//SoundManager::Instance()->playMusic("background", 0);
	
	background.render(m_renderer);
	player.render(m_renderer);
	ball.render(m_renderer);	
	
	for (int i = 0; i < Blocks::BLOCKS_COLUMNS * Blocks::BLOCKS_ROWS; i++) {
		if (blocksArr[i].isAlive()) {
			blocksArr[i].render(blocksArr[i].rect.x, blocksArr[i].rect.y, m_renderer);
		}
	}
	font.render("blocksText", 645, 150, m_renderer);
	font.render("lives", 645, 175, m_renderer);
}

void PlayState::setBlocks() {
	int i = 0;
	for (int x = 0; x < Blocks::BLOCKS_COLUMNS; x++) {
		for (int y = 0; y < Blocks::BLOCKS_ROWS; y++) {
			blocksArr[i].rect.x = x * Blocks::BLOCKS_WIDTH + Game::GAME_AREA_X1 + x * 3;
			blocksArr[i].rect.y = (y * 2) * Blocks::BLOCKS_HEIGHT / 4 + Game::GAME_AREA_Y1 + y * 3;
			blocksArr[i].rect.w = Blocks::BLOCKS_WIDTH;
			blocksArr[i].rect.h = Blocks::BLOCKS_HEIGHT / 4;
			blocksArr[i].setAlive(true);
			i++;
		}
	}
}

int PlayState::numBlocksLeft() {
	int result = 0;
	for (int i = 0; i < Blocks::BLOCKS_COLUMNS * Blocks::BLOCKS_ROWS; i++) {
		if (blocksArr[i].isAlive()) {
			result++;
		}
	}
	return result;
}