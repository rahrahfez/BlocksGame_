#include "Game.h"

int main(int argc, char* argv[]) {
	Game game;
	if (game.init()) {		
		game.load();
		while (game.isRunning()) {	
			game.handleInput();
			game.update();
			game.render();
		}
	}
	game.close();
	return 0;
}

