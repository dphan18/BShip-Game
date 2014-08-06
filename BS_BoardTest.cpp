
#include <iostream>
#include "BS_Board.h"
#include "ConsoleDisplay.h"

using namespace std;

int main()
{	
	ConsoleDisplay display(3, 30, 40);
	BS_Board board(cin, cout);

	display.clear();
	board.writeShipGrid(display);
	board.writeAttackGrid(display);
	display.refresh();

	return 0;
}
