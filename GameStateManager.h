#ifndef GAMESTATEMANAGER_H
#define GAMESTATEMANAGER_H

class GameStateManager {
	
public:
	GameStateManager();
	~GameStateManager();
	void popState();
	void pushState();
	bool isValid();
}
#endif
