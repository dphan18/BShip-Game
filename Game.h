#ifndef GAME_H
#define GAME_H

#include <iostream>

class Game {
public:
	// Constructor
	Game() : finished(false) { }

	bool gameOver() {
		return finished;
	}

	virtual void gameUpdate() = 0;
	
	// Destructor
	virtual ~Game() { }

protected:
	void gameEnd() {
		finished = true;
	}

private:
	bool finished;
};

#endif // GAME_H
