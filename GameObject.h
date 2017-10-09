#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <SDL.h>

class GameObject {
public:
	virtual ~GameObject() {}
	virtual bool load(SDL_Renderer* m_renderer) = 0;
	virtual void render(SDL_Renderer* m_renderer) = 0;
	virtual void free() = 0;
};
#endif