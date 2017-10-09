#ifndef GAME_H
#define GAME_H
#include <SDL.h>
#include <vector>
#include "GameState.h"

class GameState;

class Game {
	SDL_Renderer* m_renderer;
	SDL_Window* m_window;
	std::vector<GameState*>m_states;
	bool m_running;
public:
	static const int SCREEN_WIDTH = 800;
	static const int SCREEN_HEIGHT = 600;

	static const int GAME_AREA_X1 = 20;
	static const int GAME_AREA_X2 = 600;
	static const int GAME_AREA_Y1 = 20;
	static const int GAME_AREA_Y2 = 600;

	Game() : m_window(0), m_renderer(0) {}
	~Game() {}
	bool init();
	void load();

	void handleInput();
	void render();
	void update();
	void close();

	void changeState(GameState* s);
	void pushState(GameState* s);
	void popState();

	bool isRunning() { return m_running; }
};
#endif
