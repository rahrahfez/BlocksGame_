#ifndef BACKGROUND_H
#define BACKGROUND_H
#include "GameObject.h"
#include "TextureManager.h"

class Background : public GameObject {
	int m_x, m_y, m_width, m_height;
	TextureManager backgroundTexture;
public:
	Background();
	~Background();
	bool load(SDL_Renderer* m_renderer);
	void render(SDL_Renderer* m_renderer);
	void free();
};
#endif