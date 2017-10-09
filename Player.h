#ifndef PLAYER_H
#define PLAYER_H
#include "GameObject.h"
#include "InputHandler.h"
#include "Timer.h"
#include "Vector2D.h"
#include "TextureManager.h"

class Player : public GameObject {
	Vector2D m_pos;
	Vector2D m_vel;

	InputHandler input;
	Timer timer;
	int m_lives;
	TextureManager playerTexture;
public:
	static const int PLAYER_WIDTH = 100;
	static const int PLAYER_HEIGHT = 20;

	SDL_Rect rect;
	float getXPos() const;
	float getYPos() const;

	Player();
	~Player();

	int getLives() const { return m_lives; }
	void setLives(int lives) { m_lives = lives; }

	bool load(SDL_Renderer* m_renderer);
	void render(SDL_Renderer* m_renderer);
	void update();
	void handleMovement(const SDL_Event& e, uint32_t delta);
	void free();
};
#endif
