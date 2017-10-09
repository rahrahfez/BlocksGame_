#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H
#include <SDL.h>

class InputHandler {
	const Uint8* m_keyStates;
	bool m_left;
	bool m_right;
public:
	InputHandler();
	void update();
	bool isKeyDown(SDL_Scancode key);

	bool left() { return m_left; }
	bool right() { return m_right; }
	void setLeft(bool flag) { m_left = flag; }
	void setRight(bool flag) { m_right = flag; }
};

#endif
