#ifndef BALL_H
#define BALL_H
#include "GameObject.h"
#include "TextureManager.h"
#include "Vector2D.h"

class Ball : public GameObject {
	Vector2D m_pos;
	Vector2D m_vel;
	bool m_locked;
	TextureManager ballTexture;
public:
	static const int BALL_WIDTH = 20;
	static const int BALL_HEIGHT = 20;

	SDL_Rect rect;

	Ball();
	~Ball();

	void setXPos(float pos);
	void setYPos(float pos);
	void setXVel(float vel);
	void setYVel(float vel);

	float getXPos() const;
	float getYPos() const;
	float getXVel() const;
	float getYVel() const;

	bool isLocked() { return m_locked; }
	void unlockBall(SDL_Event& e);
	void lockBall();

	bool load(SDL_Renderer* m_renderer);
	void render(SDL_Renderer* m_renderer);
	void update();
	void free();
};
#endif
