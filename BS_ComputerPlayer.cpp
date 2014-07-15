#include <cstdlib>
#include <ctime>
#include "BS_ComputerPlayer.h"
#include "BS_Board.h"

using namespace std;

#define GENIUS_COMPUTER 1

BS_ComputerPlayer::BS_ComputerPlayer(std::string name, 
					char number,
					std::istream& i,
					std::ostream& o) : BS_Player(name, number, i, o, false)
{
	for (int r = 1; r < 1 + BS_Board::boardSize; ++r) {
		for (int c = 'A'; c < 'A' + BS_Board::boardSize; ++c) {
			coords.push_back(coord_t(c, r));
		}
	}

	srand(time(0)); // Seed rand
}

void BS_ComputerPlayer::move(char *c, char *r)
{
#if DUMB_COMPUTER
	static int i = 1;
	static int j = 'A';
	
	if ('A' + BS_Board::boardSize == j) {
		j = 'A';
		*c = j;
		*r = ++i;
	} else {
		*c = j++;
		*r = i;
	}
#elif SMART_COMPUTER
	list<coord_t>::iterator c_it = coords.begin();
	int count = (rand() % coords.size());
	while (count--) {
		c_it++;
	}
	*c = (*c_it).col;
	*r = (*c_it).row;
	coords.erase(c_it);
#elif GENIUS_COMPUTER
	list<coord_t>::iterator c_it;
	
	bool success = false;
	
	while (!success && strategy.valid()) { // Use apriori knowlege
		strategy.getMove(c, r);
		for (c_it = coords.begin(); c_it != coords.end(); ++c_it) {
			if (*c == (*c_it).col && *r == (*c_it).row) {

				success = true;
				coords.erase(c_it);
				break;
			}
		}
	} 

	if (!success) { // Select random coordinate

		int count = (rand() % coords.size());
		c_it = coords.begin();
		while (count--) {
			c_it++;
		}
		*c = (*c_it).col;
		*r = (*c_it).row;
		coords.erase(c_it);
	}
#endif
}
