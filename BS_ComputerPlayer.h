#ifndef BS_COMPUTERPLAYER_H
#define BS_COMPUTERPLAYER_H

#include <string>
#include <iostream>
#include "BS_Player.h"

class BS_ComputerPlayer : public BS_Player {

public:
	BS_ComputerPlayer(std::string name, 
				char number,
				std::istream& i,
				std::ostream& o) : BS_Player(name, number, i, o, false) { }

	void move(char *c, char *r);
};

#endif // BS_COMPUTERPLAYER_H
