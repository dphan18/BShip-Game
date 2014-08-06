#include <string>
#include "BattleShip.h"
#include "BS_HumanPlayer.h"
#include "BS_ComputerPlayer.h"

using namespace std;

BattleShip::BattleShip(istream& input, ostream& output) : 	
				in(input), 
				out(output), 
				display(3, 40, 40),
				p1Board(in, out),
				p2Board(in, out),
				p1(in, out),
				p2()
{
	p1Board.placeShips(display); // Human Player will be prompted
	p2Board.placeShips(); // Computer will pick at random
	display.clear();
}

void BattleShip::gameUpdate()
{
	char c, r;
	p1Board.writeShipGrid(display);
	p1Board.writeAttackGrid(display);
	display.refresh();

	p1.move(&c, &r, p1Board);

	display.clear();

	display.write(2, p1.name() + "'s turn");
	if (p2Board.checkShot(c, r, display)) {
		p1Board.markHit(c, r);
	}

	if (p2Board.fleetSunk()) {
		p1Board.writeShipGrid(display);
		p1Board.writeAttackGrid(display);
		display.write(2, p1.name() + " wins!!!");
		display.refresh();
		gameEnd();
		return;
	}

	display.write(2, p2.name() + "'s turn");
	p2.move(&c, &r, p2Board);
	if (p1Board.checkShot(c, r, display)) {
		p2Board.markHit(c, r);
		p2.update(c, r);
	}
	
	if (p1Board.fleetSunk()) {
		p1Board.writeShipGrid(display);
		p1Board.writeAttackGrid(display);
		display.write(2, p2.name() + " wins!!!");
		display.refresh();
		gameEnd();
		return;
	}
}

