#ifndef BLOCKS_H
#define BLOCKS_H
#include "GameObject.h"
#include "TextureManager.h"

class Blocks : public GameObject {
	bool m_alive;
	TextureManager blocksTexture;
public:
	static const int BLOCKS_WIDTH = 50;
	static const int BLOCKS_HEIGHT = 100;
	static const int BLOCKS_COLUMNS = 11;
	static const int BLOCKS_ROWS = 5;

	SDL_Rect rect;
	Blocks();
	~Blocks() {}
	bool setAlive(bool isAlive) { 
		m_alive = isAlive;
		return m_alive;
	}
	bool isAlive() { return m_alive; }
	bool load(SDL_Renderer* m_renderer);
	void render(int x, int y, SDL_Renderer* m_renderer);
	void render(SDL_Renderer* m_renderer) {} // needed for GameObject
	void free();
};

#endif
