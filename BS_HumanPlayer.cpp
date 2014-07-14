#include "BS_HumanPlayer.h"
#include <string>
#include <cctype>
#include <cstdlib>

using namespace std;

bool BS_HumanPlayer::readUserShotInput(char *col, char *row)
{
	char c;
    	string str;

    	while(in.get(c) && isdigit(c)) {
        	str.push_back(c);
	}

    	*row = atoi(str.c_str());

	if (*row > 10 || *row < 1) {
		return false;
	}

	if (isalpha(c)) {
		*col = toupper(c);
	} else {
		return false;
	}

	if (*col < 'A' || *col > 'J') {
		return false;
	}

	return true;
}

void BS_HumanPlayer::move(char *c, char *r)
{	
	board.displayBoard(true);

	bool success = false;	
	do {
		out << "Enter your shot (ex. 1A):";

		while(in.get() != '\n');
	
		if (!readUserShotInput(c, r)) {
			continue;
		}

		success = makeAttempt(*c, *r);

	} while (!success);
}
