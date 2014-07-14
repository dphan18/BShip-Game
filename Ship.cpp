#include <stdexcept>
#include "Ship.h"

using namespace std;

bool Ship::checkSize(char size, char col1, char row1, char col2, char row2)
{
	if (row1 == row2) {
		if (col1 > col2) {
			if ((col1 - col2) + 1 == size) {
				return true;
			}
		} else {
			if ((col2 - col1) + 1 == size) {
				return true;
			}
		}
	}

	if (col1 == col2) {
		if (row1 > row2) {
			if ((row1 - row2) + 1 == size) {
				return true;
			}
		} else {
			if ((row2 - row1) + 1 == size) {
				return true;
			}
		}
	}

	return false;
}

void buildShipSections(vector<BS_ShipTile>& tiles, char col1, char row1, char col2, char row2)
{
	int i;

	if (row1 == row2) {
		if (col1 < col2) {
			for (i = col1; i <= col2; ++i) {
				tiles.push_back(BS_ShipTile(i,row1));
			}
		} else {
			for (i = col2; i <= col1; ++i) {
				tiles.push_back(BS_ShipTile(i, row1));
			}
		} 
	} else {
		if (row1 < row2) {
			for (i = row1; i <= row2; ++i) {
				tiles.push_back(BS_ShipTile(col1, i));
			}
		} else {
			for (i = row2; i <= row1; ++i) {
				tiles.push_back(BS_ShipTile(col1, i));
			}
		}
	}
}

Ship::Ship(const shipInfo& i, char c1, char r1, char c2, char r2)
{
	info = i;
	buildShipSections(sections, c1, r1, c2, r2);
}

bool Ship::checkHit(char col, char row)
{
	for (ship_it it = sections.begin(); it != sections.end(); ++it) {
		if ((*it).getCol() == col && (*it).getRow() == row) {
			(*it).setHit();
			// FIXME: When should we check sunk cond?
			return true;
		}
	}
	return false;
}

bool Ship::sunk()
{
	for(ship_it it = sections.begin(); it != sections.end(); ++it) {
		if ((*it).getHit() == false)
			return false;
	}
	return true;
}

bool Ship::checkLocation(char col, char row)
{
	for (ship_it it = sections.begin(); it != sections.end(); ++it) {
		if ((*it).getCol() == col && (*it).getRow() == row)
			return true;
	}
	return false;
}

bool Ship::collision(Ship& s)
{
	bool ret = false;
	for (ship_it it1 = s.sections.begin(); it1 != s.sections.end(); ++it1) {
		for (ship_it it2 = sections.begin(); it2 != sections.end(); ++it2) {
			if(	((*it1).getCol() == (*it2).getCol()) &&
				((*it1).getRow() == (*it2).getRow())	) {
				ret = true;
			}
		}
	}
	return ret;
}
