#include <string>
#include <cctype>
#include <cstdlib>
#include "BS_Board.h"
#include "BS_ShipTile.h"

using namespace std;

string const shipGrid =     "        Ship Grid      ";
string const attackGrid = "       Attack Grid     ";
string const boardTop =     "  |A|B|C|D|E|F|G|H|I|J|";
string const rowStart[BS_Board::boardSize] = {
				" 1|",
				" 2|",
				" 3|",
				" 4|",
				" 5|",
				" 6|",
				" 7|",
				" 8|",
				" 9|",
				"10|" };

char const shipNoHit = 'O';
char const shipHit = '@';
char const boardNoHit = ' ';
char const boardHit = 'X';

string const legend =	"---Legend---   \nO Ship         \n@ Ship with hit\nX Missed Attack\n";
		

void displayTile(BS_BoardTile& tile, ostream& out)
{
	int sel = ((int)tile.getHit() << 1) | (int)tile.getShip(); // 0 - 3
	switch(sel) {
	case 0:
		out << boardNoHit << '|';
		break;
	case 1:
		out << shipNoHit << '|';
		break;
	case 2:
		out << boardHit << '|';
		break;
	case 3:
		out << shipHit << '|';
		break;
	}
}

void BS_Board::displayBoard(bool full)
{
	vector<BS_BoardTile>::iterator b_it, a_it;
	int i = 0;
	
	out << endl;
	if (full) {
		out << shipGrid << attackGrid << endl;
		out << boardTop << ' ' << boardTop << endl;
	} else {
		out << shipGrid << endl;
		out << boardTop << endl;	
	}
	
	if (full) {
		a_it = attempts.begin();
		for (b_it = board.begin(), a_it = attempts.begin(); b_it != board.end(); ++b_it) {
			if ((*b_it).getCol() == 'A') {
				out << rowStart[i];
				displayTile(*b_it, out);
			} else if ((*b_it).getCol() == 'J') {
				displayTile(*b_it, out);
				// Display attempts row
				out << ' ' << rowStart[i++];
				for (;(*a_it).getCol() != 'J' && a_it != attempts.end(); ++a_it) {
					displayTile(*a_it, out);
				}
				displayTile(*a_it++, out);
				//
				out << endl;
			} else {
				displayTile(*b_it, out);
			}		
		}
		out << legend;
	} else {
		for (b_it = board.begin(); b_it != board.end(); ++b_it) {

			if ((*b_it).getCol() == 'A') {
				out << rowStart[i++];
				displayTile(*b_it, out);
			} else if ((*b_it).getCol() == 'J') {
				displayTile(*b_it, out);
				out << endl;
			} else {
				displayTile(*b_it, out);
			}		
		}
		out << legend;
	}
}

BS_Board::BS_Board(istream& i, ostream& o, bool show) : in(i), out(o), showBoard(show) 
{ 
	// Initialize board
	for (int row = 1; row < 1 + boardSize; ++row) {
		for(int col = 'A'; col < 'A' + boardSize; ++col) {
			board.push_back(BS_BoardTile(col, row));
		}
	}
	// Initialize attempts
	for (int row = 1; row < 1 + boardSize; ++row) {
		for(int col = 'A'; col < 'A' + boardSize; ++col) {
			attempts.push_back(BS_BoardTile(col, row));
		}
	}
}

bool readUserShipInput(istream& in, char *col1, char *row1, char *col2, char *row2)
{
	char c;
    string str;

    while(in.get(c) && isdigit(c))
        str.push_back(c);

    *row1 = atoi(str.c_str());

    str.clear();

    if (isalpha(c)) {
        *col1 = toupper(c);
    } else {
        return false;
	}

    in.get(c); // consume space
    if (c != ' ')
        return false;

    while(in.get(c) && isdigit(c))
        str.push_back(c);

    *row2 = atoi(str.c_str());

    str.clear();

    if (isalpha(c)) {
        *col2 = toupper(c);
    } else {
        return false;
	}

	return true;
}

bool offBoard(char c1, char r1, char c2, char r2)
{
	if(	r1 < 1 || r1 > 10 || r2 < 1 || r2 > 10 ||
		c1 < 'A' || c1 > 'J' || c2 < 'A' || c2 > 'J')
		return true;
	else
		return false;
}

bool BS_Board::shipCollision(Ship& ship)
{
	vector<Ship>::iterator vs_it;

	for (vs_it = ships.begin(); vs_it != ships.end(); ++vs_it) {
		if ((*vs_it).collision(ship)) {
			return true;
		}
	}

	return false;
}

void BS_Board::markBoard(Ship& ship)
{
	vector<BS_ShipTile>::iterator s_it;

	for (s_it = ship.shipBegin(); s_it != ship.shipEnd(); ++s_it) {

		int i = ((*s_it).getRow() - 1) * boardSize;
		i = i + (*s_it).getCol() - 'A';

		board[i].setShip();
	}
}

void BS_Board::shipPlacementPrompt(const Ship::shipInfo& info)
{
	char c1, r1, c2, r2;	
	
	bool success = false;

	do {
		out << info.type << "(size " << (int)info.size << "):";
	
		while(in.get() != '\n');

		if (!readUserShipInput(in, &c1, &r1, &c2, &r2)) {
			continue;
		}
		
		if (offBoard(c1, r1, c2, r2)) {
			continue;
		}
		
		if (!Ship::checkSize(info.size, c1, r1, c2, r2)) {
			continue;
		}

		Ship s(info, c1, r1, c2, r2);
        	if (shipCollision(s)) { //
                	continue;
        	} else {
			ships.push_back(s); //
			markBoard(s);
			success = true;
		}
					
	} while (!success);

	displayBoard(false);
}

void BS_Board::placeShips()
{
	vector<Ship::shipInfo>::const_iterator s_it;

	if (showBoard) {
		displayBoard(false);
		out << "Enter ship placments by specifying the the end " << 
			"points of each ship. Ex. Patrol Boat (size 2): 1A 1B\n" << endl;
	}
	
	for (s_it = shipTypes.begin(); s_it != shipTypes.end(); ++s_it) {
		if (showBoard) {
			shipPlacementPrompt(*s_it);
		} else {
			// Random Placement
		}
	}

	if (!showBoard) { // Temporarily placing computer ships in fixed locations
		ships.push_back(Ship(shipTypes[AIRCRAFT], 'A', 1, 'E', 1));
		ships.push_back(Ship(shipTypes[BATTLE], 'A', 2, 'D', 2));
		ships.push_back(Ship(shipTypes[DESTROYER], 'A', 3, 'C', 3));
		ships.push_back(Ship(shipTypes[SUB], 'A', 4, 'C', 4));
		ships.push_back(Ship(shipTypes[PATROL], 'A', 5, 'B', 5));
	}
}

bool BS_Board::makeAttempt(char c, char r)
{
	int i = ((r - 1) * boardSize) + c - 'A';

	if (attempts[i].getHit()) {
		return false;
	} else {
		attempts[i].setHit();
		return true;
	}
}

bool BS_Board::checkShot(char c, char r)
{
	vector<Ship>::iterator s_it;

	for (s_it = ships.begin(); s_it != ships.end(); ++s_it) {
		if ((*s_it).checkHit(c, r)) {
			out << "\n" << (*s_it).type() << " was hit!" << endl;
			int i = ((r - 1) * boardSize) + c - 'A';
			board[i].setHit();
			return true;
		}
	}
	return false;
}

void BS_Board::markHit(char c, char r)
{
	int i = ((r - 1) * boardSize) + c - 'A';
	attempts[i].setShip(); // Marks a ship in this tile

	/* For computer player
	if (strategy.valid()) {
		strategy.update(c, r);
	} else {
		stratey.set(c, r);
	}
	*/
}

bool BS_Board::fleetSunk()
{
	vector<Ship>::iterator s_it;
	for (s_it = ships.begin(); s_it != ships.end(); ++s_it) {
		if (!(*s_it).sunk()) {
			return false;
		}
	}
	return true;
}
