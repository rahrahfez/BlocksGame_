#include "PauseState.h"
#include "PlayState.h"

void PauseState::init(SDL_Renderer* m_renderer) {
	pauseStateTexture.load("images/gamepaused.bmp", "gamepause", m_renderer);
}

void PauseState::close() {
	pauseStateTexture.clearTexureMap("gamepause");
}

void PauseState::handleEvents(Game* g, SDL_Event& e) {
	switch (e.key.keysym.sym) {
	case SDLK_ESCAPE:
		g->pushState(&PlayState::Instance());
	}
}

void PauseState::update() {

}

void PauseState::render(SDL_Renderer* m_renderer) {
	pauseStateTexture.draw("gamepause", 0, 0, Game::SCREEN_WIDTH, Game::SCREEN_HEIGHT, m_renderer);
}