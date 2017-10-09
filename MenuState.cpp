#include "MenuState.h"
#include "PlayState.h"

void MenuState::init(SDL_Renderer* m_renderer) {
	menuStateTexture.load("images/splash.bmp", "splash", m_renderer);
}

void MenuState::close() {
	menuStateTexture.clearTexureMap("splash");
}

void MenuState::handleEvents(Game* g, SDL_Event& e) {
	switch (e.key.keysym.sym) {
	case SDLK_RETURN:
		close();
		g->changeState(&PlayState::Instance());
	}
}

void MenuState::update() {

}

void MenuState::render(SDL_Renderer* m_renderer) {
	menuStateTexture.draw("splash", 0, 0, Game::SCREEN_WIDTH, Game::SCREEN_HEIGHT, m_renderer);
}
