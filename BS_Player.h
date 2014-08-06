#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include "BS_Board.h"
#include "ConsoleDisplay.h"

class BS_Player {
public:
	BS_Player() { }
	BS_Player(std::string name) : n(name) { }

	std::string name() {
		return n;
	}
	
	virtual void move(char* c, char* r, BS_Board& board) = 0;

	virtual ~BS_Player() { }

protected:
	std::string n;
};

#endif // PLAYER_H
