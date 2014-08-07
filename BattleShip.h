#ifndef BATTLESHIP_H
#define BATTLESHIP_H

#include <iostream>
#include <memory>
#include "Game.h"
#include "BS_HumanPlayer.h"
#include "BS_ComputerPlayer.h"
#include "BS_Board.h"
#include "ConsoleDisplay.h"

static const char screenPanels[] = {30, 30, 60};
static const char screenHeight = 40;

class BattleShip : public Game {
	friend class BS_HumanPlayer;
	friend class BS_ComputerPlayer;
public:
	BattleShip(std::istream&, std::ostream&);

	void gameUpdate();

private:
	std::istream& in;
	std::ostream& out;
	ConsoleDisplay display;
	BS_Board p1Board, p2Board;
	BS_HumanPlayer p1;
	BS_ComputerPlayer p2;
};

#endif // BATTLESHIP_H
