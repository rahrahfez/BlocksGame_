#include "InputHandler.h"
#include <SDL.h>

InputHandler::InputHandler() : m_keyStates(0), m_left(false), m_right(false) {}

void InputHandler::update() {
	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		m_keyStates = SDL_GetKeyboardState(NULL);
		if (e.type == SDL_QUIT) {
			SDL_Quit();
		}
	}
}

bool InputHandler::isKeyDown(SDL_Scancode key) {
	if (m_keyStates != 0) {
		if (m_keyStates[key] == 1) {
			return true;
		}
		else {
			return false;
		}
	}
	return false;
}