#ifndef BS_SHIPTILE_H
#define BS_SHIPTILE_H

#include "BS_Tile.h"

class BS_ShipTile : public BS_Tile {
public:
	// Constructor
	BS_ShipTile() : h(false) { }
	BS_ShipTile(char c, char r) : BS_Tile(c, r), h(false) { }

	void setHit() {
		h = true;
	}

	bool getHit() {
		return h;
	}
private:
	bool h;
};

#endif // BS_SHIPTILE_H
