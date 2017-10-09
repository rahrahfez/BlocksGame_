#include "Game.h"
#include "GameObject.h"
#include "SoundManager.h"
#include "MenuState.h"

bool Game::init() {
	m_running = true;
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		m_window = SDL_CreateWindow("Blocks Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);	
		m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
		TTF_Init();
		Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096);
	}
	return m_running;
}

void Game::load() {
	changeState(&MenuState::Instance());
	m_states.back()->init(m_renderer);
}

void Game::render() {
	SDL_RenderClear(m_renderer);	
	m_states.back()->render(m_renderer);
	SDL_RenderPresent(m_renderer);
}

void Game::handleInput() {
	SDL_Event e;
	const Uint8* keys = SDL_GetKeyboardState(NULL);
	while (SDL_PollEvent(&e) != 0) {
		if (e.type == SDL_QUIT) {
			m_states.back()->close();
			close();
		}
		m_states.back()->handleEvents(this, e);
	}
}

void Game::update() {
	m_states.back()->update();
}

void Game::changeState(GameState* s) {
	// clean up current state
	if (!m_states.empty()) {
		m_states.back()->close();
		m_states.pop_back();
	}
	//store and init the new state
	m_states.push_back(s);
	m_states.back()->init(m_renderer);
}
/*
Whereas ChangeState() pushes a state onto the stack and removes the previous state, PushState() pauses the previous state
before pushing a new state onto the stack, this state can then be removed and the previous state resumed. Extremely
useful for pausing.
*/
void Game::pushState(GameState* s) {
	// pause current state
	//if (!m_states.empty()) m_states.back()->Pause();

	m_states.push_back(s);
	m_states.back()->init(m_renderer);
}
/*
Remove and resume previous state.
*/
void Game::popState() {
	// cleanup the current state
	if (!m_states.empty()) {
		m_states.back()->close();
		m_states.pop_back();
	}
}

void Game::close() {
	SDL_DestroyWindow(m_window);
	SDL_DestroyRenderer(m_renderer);

	m_window = NULL;
	m_renderer = NULL;

	TTF_Quit();
	Mix_CloseAudio();

	SDL_Quit();
}
