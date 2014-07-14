#ifndef GAME_H
#define GAME_H

#include <iostream>

class Game {
public:
	Game() : finished(false) { }
	virtual void gameUpdate() = 0;
	bool gameOver() {
		return finished;
	}
	
	virtual ~Game() { }

protected:
	void gameEnd() {
		finished = true;
	}

private:
	bool finished;
};

#endif // GAME_H
