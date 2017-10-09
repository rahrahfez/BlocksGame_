#ifndef COLLISION_H
#define COLLISION_H
#include <SDL.h>

struct Collision {
	bool RectsOverlap(SDL_Rect rect1, SDL_Rect rect2) {
		if (rect1.x >= rect2.x + rect2.w) return false;
		if (rect1.y >= rect2.y + rect2.h) return false;
		if (rect2.x >= rect1.x + rect1.w) return false;
		if (rect2.y >= rect1.y + rect1.h) return false;
		return true;
	}
};
#endif
