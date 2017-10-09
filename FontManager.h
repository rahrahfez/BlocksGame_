#ifndef FONTMANAGER_H
#define FONTMANAGER_H
#include "TextureManager.h"

class FontManager {
	int m_x, m_y;
	TTF_Font* m_font;
	TextureManager fontTexture;
public:
	FontManager() : m_x(0), m_y(0) { m_font = NULL; }
	~FontManager() {}
	void init();
	bool load(std::string id, std::string str, SDL_Color textColor, SDL_Renderer* m_renderer);
	void render(std::string id, int x, int y, SDL_Renderer* m_renderer);
	void close(std::string id);
}; typedef FontManager fontmanager;
#endif
