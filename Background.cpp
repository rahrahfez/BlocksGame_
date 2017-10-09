#include "Game.h"
#include "Background.h"


Background::Background() : GameObject(), m_x(0), m_y(0), m_width(0), m_height(0) {}

Background::~Background() {}

bool Background::load(SDL_Renderer* m_renderer) {
	if (backgroundTexture.load("images/background.bmp", "background", m_renderer) == NULL) return false;
	return true;
}

void Background::free() {
	backgroundTexture.clearTexureMap("background");
}

void Background::render(SDL_Renderer* m_renderer) {
	backgroundTexture.draw("background", m_x, m_y, Game::SCREEN_WIDTH, Game::SCREEN_HEIGHT, m_renderer);
}