#ifndef BS_BOARD_H
#define BS_BOARD_H

#include <vector>
#include <queue>
#include <string>
#include <iostream>
#include "BS_BoardTile.h"
#include "Ship.h"
#include "ConsoleDisplay.h"

class BS_Board {
public:
	static int const boardSize = 10;

	const std::vector<Ship::shipInfo> shipTypes = {{ "Aircraft Carrier", 5},
							{ "Battle Ship", 4},
							{ "Destroyer", 3},
							{ "Submarine", 3},
							{ "Patrol Boat", 2}};

	typedef enum {AIRCRAFT, BATTLE, DESTROYER, SUB, PATROL} ship_t;

	// Constructors
	BS_Board(std::istream& i, std::ostream& o);

	void placeShips(ConsoleDisplay& display);
	void placeShips();
	bool makeAttempt(char c, char r);
	bool checkShot(char c, char r, ConsoleDisplay& display);
	void markHit(char c, char r);
	bool fleetSunk();
	void writeShipGrid(ConsoleDisplay& display);
	void writeAttackGrid(ConsoleDisplay& display);
private:
	bool shipCollision(Ship&);
	void shipPlacementPrompt(const Ship::shipInfo&, ConsoleDisplay& display);
	void shipPlacementRandom(const Ship::shipInfo&);
	void markBoard(Ship&);
	std::istream& in;
	std::ostream& out;
	std::vector<Ship> ships;
	std::vector<BS_BoardTile> shipGrid;
	std::vector<BS_BoardTile> attackGrid;
};

#endif //BS_BOARD_H
