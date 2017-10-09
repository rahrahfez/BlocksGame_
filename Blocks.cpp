#include "Blocks.h"


Blocks::Blocks() : GameObject() {
	m_alive = false;
}

bool Blocks::load(SDL_Renderer* m_renderer) {
	if(blocksTexture.load("images/blocks.bmp", "blocks", m_renderer) == NULL) return false;
	return true;
}

void Blocks::render(int x, int y, SDL_Renderer* m_renderer) {
	rect.x = x;
	rect.y = y;

	blocksTexture.draw("blocks", rect.x, rect.y, BLOCKS_WIDTH, BLOCKS_HEIGHT / 4, m_renderer);
}

void Blocks::free() {
	blocksTexture.clearTexureMap("blocks");
}