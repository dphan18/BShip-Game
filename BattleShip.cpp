#include <string>
#include "BattleShip.h"
#include "BS_HumanPlayer.h"
#include "BS_ComputerPlayer.h"

using namespace std;

BattleShip::BattleShip(istream& input, ostream& output) : in(input), out(output)
{
	string user_input;

	out << "Welcome to Battle Ship! Enter your name: ";
	in >> user_input;
	p1 = unique_ptr<BS_HumanPlayer>(new BS_HumanPlayer(user_input, 1, input, output));
	p2 = unique_ptr<BS_ComputerPlayer>(new BS_ComputerPlayer("Computer", 2, input, output));

	p1->placeShips(); // Human Player will be prompted
	p2->placeShips(); // Computer will pick at random
}

void BattleShip::gameUpdate()
{
	char c, r;
	out << "\n" << p1->name() << "'s turn" << endl;
	p1->move(&c, &r);
	if (p2->checkShot(c, r)) {
		p1->markHit(c, r);
	}

	if (p2->fleetSunk()) {
		out << p1->name() << " wins!!!" << endl;
		gameEnd();
		return;
	}

	out << "\n" << p2->name() << "'s turn" << endl;
	p2->move(&c, &r);
	if (p1->checkShot(c, r)) {
		p2->markHit(c, r);
	}
	
	if (p1->fleetSunk()) {
		out << p2->name() << " wins!!!" << endl;
		gameEnd();
		return;
	}
}

