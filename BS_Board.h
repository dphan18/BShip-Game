#include <iostream>
#include "BS_BoardTile.h"
#include "Ship.h"

typedef enum {AIRCRAFT, BATTLE, DESTROYER, SUB, PATROL} ship_t;

class BS_Board {
public:
	static int const boardSize = 10;

	BS_Board(std::istream& i, std::ostream& o, bool show);

	std::vector<shipInfo> const shipTypes = {	{ "Aircraft Carrier", 5},
							{ "Battle Ship", 4},
							{ "Destroyer", 3},
							{ "Submarine", 3},
							{ "Patrol Boat", 2}};

	void placeShips();

	bool makeAttempt(char c, char r);

	bool checkShot(char c, char r);

	void markHit(char c, char r);

	bool fleetSunk();

	void displayBoard(bool);
private:
	bool shipCollision(Ship&);
	void shipPlacementPrompt(const shipInfo&);
	void markBoard(Ship&);
	bool showBoard;
	std::istream& in;
	std::ostream& out;
	std::vector<Ship> ships;
	std::vector<BS_BoardTile> board;
	std::vector<BS_BoardTile> attempts;
};