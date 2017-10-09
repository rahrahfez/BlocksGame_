#include "Game.h"
#include "Player.h"

Player::Player() : GameObject(), m_lives(0) {
	m_pos.setX(250);
	m_pos.setY(575);
	m_vel.setX(20);
	m_vel.setY(0);
	rect.x = m_pos.getX();
	rect.y = m_pos.getY();
	rect.w = PLAYER_WIDTH;
	rect.h = PLAYER_HEIGHT;
}

Player::~Player() {

}

bool Player::load(SDL_Renderer* m_renderer) {	
	if (playerTexture.load("images/player.bmp", "player", m_renderer) == false) return false;
	return true;
}

void Player::render(SDL_Renderer* m_renderer) {
	playerTexture.draw("player", m_pos.getX(), m_pos.getY(), PLAYER_WIDTH, PLAYER_HEIGHT, m_renderer);
}

void Player::update() {
	rect.x = m_pos.getX();
	rect.y = m_pos.getY();
	if ((m_pos.getX() + PLAYER_WIDTH) < PLAYER_WIDTH + Game::GAME_AREA_X1) m_pos.setX(Game::GAME_AREA_X1);
	if ((m_pos.getX() + PLAYER_WIDTH) > Game::GAME_AREA_X2) m_pos.setX(Game::GAME_AREA_X2 - PLAYER_WIDTH);
}

void Player::handleMovement(const SDL_Event& e, uint32_t delta) {	
	const Uint8* keys = SDL_GetKeyboardState(NULL);
	if (keys[SDL_SCANCODE_LEFT]) {
		m_pos.setX(m_pos.getX() - m_vel.getX());
	}
	if (keys[SDL_SCANCODE_RIGHT]) {
		m_pos.setX(m_pos.getX() + m_vel.getX());
	}
	
}

void Player::free() {
	playerTexture.clearTexureMap("player");
}

float Player::getXPos() const {
	return m_pos.getX();
}

float Player::getYPos() const {
	return m_pos.getY();
}