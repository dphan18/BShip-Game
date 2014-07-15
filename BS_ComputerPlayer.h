#ifndef BS_COMPUTERPLAYER_H
#define BS_COMPUTERPLAYER_H

#include <string>
#include <iostream>
#include <list>
#include "BS_Player.h"
#include "coord.h"
#include "BS_Strategy.h"

class BS_ComputerPlayer : public BS_Player {

public:
	BS_ComputerPlayer(std::string name, 
				char number,
				std::istream& i,
				std::ostream& o);

	void move(char *c, char *r);

	void markHit(char c, char r) {
		board.markHit(c, r);
		strategy.update(c, r);
	}

private:
	std::list<coord_t> coords;
	BS_Strategy strategy;
};

#endif // BS_COMPUTERPLAYER_H
