#ifndef GAMESTATE_H
#define GAMESTATE_H
#include "Game.h"

class Game;

class GameState {
public:
	virtual ~GameState() {}
	virtual void init(SDL_Renderer* m_renderer) = 0;
	virtual void close() = 0;

	virtual void handleEvents(Game* g, SDL_Event& e) = 0;
	virtual void update() = 0;
	virtual void render(SDL_Renderer* m_renderer) = 0;		
};
#endif