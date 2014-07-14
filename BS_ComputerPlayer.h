#ifndef BS_COMPUTERPLAYER_H
#define BS_COMPUTERPLAYER_H

#include <string>
#include <iostream>
#include <list>
#include "BS_Player.h"

typedef struct coord_ {
	char col;
	char row;
	
	coord_(char c, char r) {
		col = c;
		row = r;
	}
} coord;

class BS_ComputerPlayer : public BS_Player {

public:
	BS_ComputerPlayer(std::string name, 
				char number,
				std::istream& i,
				std::ostream& o);

	void move(char *c, char *r);

private:
	std::list<coord> coords;
};

#endif // BS_COMPUTERPLAYER_H
