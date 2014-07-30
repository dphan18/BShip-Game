#ifndef SHIP_H
#define SHIP_H

#include <vector>
#include <string>
#include "BS_ShipTile.h"

class Ship {
public:
	typedef struct {
		std::string type;
		char size;
	} shipInfo;

	typedef std::vector<BS_ShipTile>::iterator ship_it;
 
	// Constructors
	Ship(const shipInfo&, char c1, char r1, char c2, char r2);

	std::string type() {
		return info.type;
	}

	char size() {
		return info.size;
	}

	std::vector<BS_ShipTile>::iterator shipBegin() {
		return sections.begin();
	}

	std::vector<BS_ShipTile>::iterator shipEnd() {
		return sections.end();
	}

	bool collision(Ship&);
	bool sunk();
	bool checkHit(char, char);
	bool checkLocation(char, char);
	bool static checkSize(char, char, char, char, char);

private:
	shipInfo info; 
	std::vector<BS_ShipTile> sections;
};
	
#endif // SHIP_H
