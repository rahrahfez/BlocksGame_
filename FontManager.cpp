#include "FontManager.h"
#include <iostream>

void FontManager::init() {
	m_font = TTF_OpenFont("images/brick.ttf", 18);
	if (m_font == NULL) {
		std::cout << "Failed to open font." << std::endl;
	}
}

bool FontManager::load(std::string id, std::string str, SDL_Color textColor, SDL_Renderer* m_renderer) {
	if (fontTexture.loadText(id, str, m_font, textColor, m_renderer) == NULL) return false;
	return true;
}

void FontManager::render(std::string id, int x, int y, SDL_Renderer* m_renderer) {
	fontTexture.drawText(id, x, y, m_renderer);
}

void FontManager::close(std::string id) {
	fontTexture.clearTexureMap(id);
}