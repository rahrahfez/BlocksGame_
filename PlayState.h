#ifndef PLAYSTATE_H
#define PLAYSTATE_H
#include "FontManager.h"
#include "GameState.h"
#include "Player.h"
#include "Background.h"
#include "Blocks.h"
#include "Ball.h"
#include "Timer.h"
#include "Collision.h"
#include "InputHandler.h"

class PlayState : public GameState {
	PlayState() {}
	FontManager font;
	Background background;
	Player player;
	Ball ball;
	Blocks blocksArr[Blocks::BLOCKS_COLUMNS * Blocks::BLOCKS_ROWS];
	Timer timer;
	Collision collider;
	InputHandler input;
public:
	void init(SDL_Renderer* m_renderer);
	void close();

	void handleEvents(Game* g, SDL_Event& e);
	void update();
	void render(SDL_Renderer* m_renderer);

	void setBlocks();
	int numBlocksLeft();

	static PlayState& Instance() {
		static PlayState* instance = new PlayState();
		return *instance;
	}
}; typedef PlayState playstate;
#endif
