#ifndef SHIP_H
#define SHIP_H

#include <vector>
#include <string>
#include "BS_ShipTile.h"

typedef struct {
	std::string type;
	char size;
} shipInfo;

class Ship {
public:
	typedef std::vector<BS_ShipTile>::iterator ship_it;
 
	Ship(const shipInfo&, char c1, char r1, char c2, char r2);

	std::string type() {
		return info.type;
	}

	char size() {
		return info.size;
	}

	bool collision(Ship&);

	bool sunk();

	bool checkHit(char, char);

	bool checkLocation(char, char);

	bool static checkSize(char, char, char, char, char);

	std::vector<BS_ShipTile>::iterator shipBegin() {
		return sections.begin();
	}

	std::vector<BS_ShipTile>::iterator shipEnd() {
		return sections.end();
	}

private:
	shipInfo info; 
	std::vector<BS_ShipTile> sections;// FIXME: Make private
};
	
#endif // SHIP_H
