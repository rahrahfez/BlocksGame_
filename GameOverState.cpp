#include "GameOverState.h"

void GameOverState::init(SDL_Renderer* m_renderer) {
	gameOverTexture.load("images/gameover.bmp", "gameover", m_renderer);
}

void GameOverState::close() {
	gameOverTexture.clearTexureMap("gameover");
}

void GameOverState::handleEvents(Game* g, SDL_Event& e) {

}

void GameOverState::update() {

}

void GameOverState::render(SDL_Renderer* m_renderer) {
	gameOverTexture.draw("gameover", 0, 0, Game::SCREEN_WIDTH, Game::SCREEN_HEIGHT, m_renderer);
}