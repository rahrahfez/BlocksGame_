#ifndef PAUSESTATE_H
#define PAUSESTATE_H
#include "GameState.h"
#include "TextureManager.h"

class PauseState : public GameState {
	PauseState() {}
	TextureManager pauseStateTexture;
public:
	void init(SDL_Renderer* m_renderer);
	void close();

	void handleEvents(Game* g, SDL_Event& e);
	void update();
	void render(SDL_Renderer* m_renderer);

	static PauseState& Instance() {
		static PauseState* instance = new PauseState();
		return *instance;
	}
};
#endif