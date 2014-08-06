#ifndef BS_HUMANPLAYER
#define BS_HUMANPLAYER

#include <iostream>
#include <string>
#include "BS_Player.h"
#include "BS_Board.h"

class BS_HumanPlayer : public BS_Player {

public:
	BS_HumanPlayer(std::istream& i = std::cin, std::ostream& o = std::cout);

	void move(char*, char*, BS_Board& board);
private:
	bool readUserShotInput(char*, char*);
	std::istream& in;
	std::ostream& out;
};

#endif // BS_HUMANPLAYER
