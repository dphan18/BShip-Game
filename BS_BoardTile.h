#ifndef BS_BOARDTILE_H
#define BS_BOARDTILE_H

#include "BS_Tile.h"

class BS_BoardTile : public BS_Tile {
public:
	// Constructors
	BS_BoardTile() : hit(false), ship(false) { }
	BS_BoardTile(char c, char r) : BS_Tile(c, r), hit(false), ship(false) { }

	void setHit() {
		hit = true;
	}

	bool getHit() {
		return hit;
	}

	bool getShip() {
		return ship;
	}
	
	void setShip() {
		ship = true;
	}
private:
	bool hit;
	bool ship;
};

#endif // BS_BOARDTILE_H
