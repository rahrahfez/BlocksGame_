#ifndef GAMEOVERSTATE_H
#define GAMEOVERSTATE_H
#include "GameState.h"
#include "TextureManager.h"

class GameOverState : public GameState {
	GameOverState() {}
	TextureManager gameOverTexture;
public:
	void init(SDL_Renderer* m_renderer);
	void close();

	void handleEvents(Game* g, SDL_Event& e);
	void update();
	void render(SDL_Renderer* m_renderer);

	static GameOverState& Instance() {
		static GameOverState* instance = new GameOverState();
		return *instance;
	}
};
#endif