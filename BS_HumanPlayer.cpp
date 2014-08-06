#include "BS_HumanPlayer.h"
#include <string>
#include <cctype>
#include <cstdlib>

using namespace std;

BS_HumanPlayer::BS_HumanPlayer(istream& i, ostream& o) : in(i), out(o)
{
	out << "Welcome To Battle Ship!!! What is your name?: ";

	in >> n;
}

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

void BS_HumanPlayer::move(char *c, char *r, BS_Board& board)
{	
	bool success = false;	
	do {
		out << "Enter your shot (ex. 1A):";

		while(in.get() != '\n');
	
		if (!readUserShotInput(c, r)) {
			continue;
		}

		success = board.makeAttempt(*c, *r);

	} while (!success);
}
