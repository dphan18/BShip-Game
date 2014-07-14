#ifndef BS_HUMANPLAYER
#define BS_HUMANPLAYER

#include <iostream>
#include <vector>
#include <memory>
#include "BS_Player.h"
#include "BattleShip.h"

class BS_HumanPlayer : public BS_Player {

public:
	BS_HumanPlayer(const std::string& name, 
			char number,
			std::istream& i,
			std::ostream& o
			) : BS_Player(name, number, i, o, true), in(i), out(o) { }
private:
	bool readUserShotInput(char*, char*);
	void move(char*, char*);
	std::istream& in;
	std::ostream& out;
};

#endif // BS_HUMANPLAYER
