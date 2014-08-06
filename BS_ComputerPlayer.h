#ifndef BS_COMPUTERPLAYER_H
#define BS_COMPUTERPLAYER_H

#include <string>
#include <list>
#include "BS_Player.h"
#include "coord.h"
#include "BS_Strategy.h"
#include "ConsoleDisplay.h"

class BS_ComputerPlayer : public BS_Player {

public:
	BS_ComputerPlayer(std::string name = "Computer");

	void move(char *c, char *r, BS_Board& board);

	void update(char c, char r) {
		strategy.update(c, r);
	}

private:
	std::list<coord_t> coords;
	BS_Strategy strategy;
};

#endif // BS_COMPUTERPLAYER_H
