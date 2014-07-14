#ifndef BATTLESHIP_H
#define BATTLESHIP_H

#include <iostream>
#include <memory>
#include "Game.h"
#include "BS_Player.h"

class BattleShip : public Game {
	friend class BS_HumanPlayer;
	friend class BS_ComputerPlayer;
public:
	BattleShip(std::istream&, std::ostream&);

	void gameUpdate();

private:
	std::istream& in;
	std::ostream& out;
	std::unique_ptr<BS_Player> p1, p2;
};

#endif // BATTLESHIP_H
