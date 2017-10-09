#include "Game.h"
#include "Ball.h"

Ball::Ball() : GameObject() {
	m_pos.setX(300);
	m_pos.setY(400);
	m_vel.setX(0.25f);
	m_vel.setY(0.25f);
	rect.x = m_pos.getX();
	rect.y = m_pos.getY();
	rect.w = BALL_WIDTH;
	rect.h = BALL_HEIGHT;
	m_locked = true;
}

Ball::~Ball() {}

bool Ball::load(SDL_Renderer* m_renderer) {
	if (ballTexture.load("images/ball.bmp", "ball", m_renderer) == NULL) return false;
	return true;
}

void Ball::render(SDL_Renderer* m_renderer) {
	ballTexture.draw("ball", m_pos.getX(), m_pos.getY(), BALL_WIDTH, BALL_HEIGHT, m_renderer);
}

void Ball::update() {
	rect.x = m_pos.getX();
	rect.y = m_pos.getY();

	if (m_pos.getY() < Game::GAME_AREA_Y1) {
		m_pos.setY(Game::GAME_AREA_Y1);
		m_vel.setY(m_vel.getY() * -1.0f);
	}
	if (m_pos.getY() > Game::GAME_AREA_Y2) {
		lockBall();
		
	}
	if (m_pos.getX() > Game::GAME_AREA_X2 - BALL_WIDTH) {
		m_pos.setX(Game::GAME_AREA_X2 - BALL_WIDTH);
		m_vel.setX(m_vel.getX() * -1.0f);
	}
	if (m_pos.getX() < Game::GAME_AREA_X1) {
		m_pos.setX(Game::GAME_AREA_X1);
		m_vel.setX(m_vel.getX() * -1.0f);
	}
}

void Ball::unlockBall(SDL_Event& e) {
	const Uint8* keys = SDL_GetKeyboardState(NULL);
	if (keys[SDL_SCANCODE_SPACE] && isLocked()) {
		m_locked = false;
	}
}

void Ball::lockBall() {
	m_locked = true;
}

void Ball::setXPos(float pos) {
	m_pos.setX(pos);
}

void Ball::setYPos(float pos) {
	m_pos.setY(pos);
}

void Ball::setXVel(float vel) {
	m_vel.setX(vel);
}

void Ball::setYVel(float vel) {
	m_vel.setY(vel);
}

float Ball::getXPos() const {
	return m_pos.getX();
}

float Ball::getYPos() const {
	return m_pos.getY();
}

float Ball::getXVel() const {
	return m_vel.getX();
}

float Ball::getYVel() const{
	return m_vel.getY();
}

void Ball::free() {
	ballTexture.clearTexureMap("ball");
}

