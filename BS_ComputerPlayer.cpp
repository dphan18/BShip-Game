#include "BS_ComputerPlayer.h"

using namespace std;

void BS_ComputerPlayer::move(char *c, char *r)
{
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
}
