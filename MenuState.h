#ifndef MENUSTATE_H
#define MENUSTATE_H
#include "GameState.h"
#include "TextureManager.h"

class MenuState : public GameState {
	MenuState() {}
	TextureManager menuStateTexture;
public:
	void init(SDL_Renderer* m_renderer);
	void close();

	void handleEvents(Game* g, SDL_Event& e);
	void update();
	void render(SDL_Renderer* m_renderer);

	static MenuState& Instance() {
		static MenuState* instance = new MenuState();
			return *instance;
	}
};
#endif
