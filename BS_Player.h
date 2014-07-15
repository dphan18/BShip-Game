#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include "BS_Board.h"

class BS_Player {
public:
	BS_Player(std::string name, 
			char number, 
			std::istream& in, 
			std::ostream& out,
			bool show) 
			: num(number), n(name), board(in, out, show) { }

	std::string name() {
		return n;
	}
	
	char number() {
		return num;
	}

	void placeShips() {
		board.placeShips();
	}

	bool makeAttempt(char c, char r) {
		return board.makeAttempt(c, r);
	}

	bool checkShot(char c, char r) {
		return board.checkShot(c, r);
	}
	
	virtual void markHit(char c, char r) {
		board.markHit(c, r);
	}

	bool fleetSunk() {
		return board.fleetSunk();
	}

	virtual void move(char*, char*) = 0;

	virtual ~BS_Player() { }

protected:
	BS_Board board;

private:
	char num;
	std::string n;
};

#endif // PLAYER_H
