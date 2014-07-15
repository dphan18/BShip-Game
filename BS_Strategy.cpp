#include "BS_Strategy.h"

/*
	Called on a successful hit
*/
void BS_Strategy::update(char c, char r) {

	if (!valid()) {
		set(c, r);
	} else {
		successful = true;
		if (UP == last_dir || DOWN == last_dir) {
			left = NOTLIKELY;
			right = NOTLIKELY;
		} else {
			up = NOTLIKELY;
			down = NOTLIKELY;
		}
	}
}

bool BS_Strategy::valid() 
{
	if (firstTry.col) {
		return true;
	} else {
		return false;
	}
}

void BS_Strategy::reset() {
	firstTry.col = 0;
	firstTry.row = 0;
	lastTry.col = 0;
	lastTry.row = 0;
	up = MAYBE;
	down = MAYBE;
	left = MAYBE;
	right = MAYBE;
	successful = true;
	last_dir = NONE;
}

void BS_Strategy::set(char c, char r) {
	firstTry.col = c;
	firstTry.row = r;
	lastTry.col = c;
	lastTry.row = r;
}

bool BS_Strategy::getMove(char *c, char *r)
{
	if (!successful) {
		if (UP == last_dir) {
			up = NOTLIKELY;
		} else if (DOWN == last_dir) {
			down = NOTLIKELY;
		} else if (LEFT == last_dir) {
			left = NOTLIKELY;
		} else if (RIGHT == last_dir) {
			right = NOTLIKELY;
		}
	}

	bool success = false;
	while(!success) {
		if (MAYBE == up) {

			if (UP != last_dir) {
				last_dir = UP;
				lastTry = firstTry;	
			} 

			if (1 == lastTry.row) {
				up = NOCHANCE;
			} else {
				--lastTry.row;
				success = true;
			}
		} else if (MAYBE == down) {

			if (DOWN != last_dir) {
				last_dir = DOWN;
				lastTry = firstTry;	
			} 

			if (10 == lastTry.row) {
				down = NOCHANCE;
			} else {
				++lastTry.row;
				success = true;
			}
		} else if (MAYBE == left) {

			if (LEFT != last_dir) {
				last_dir = LEFT;
				lastTry = firstTry;	
			} 

			if ('A' == lastTry.col) {
				left = NOCHANCE;
			} else {
				--lastTry.col;
				success = true;
			}
		} else if (MAYBE == right) {

			if (RIGHT != last_dir) {
				last_dir = RIGHT;
				lastTry = firstTry;	
			} 

			if ('J' == lastTry.col) {
				right = NOCHANCE;
			} else {
				++lastTry.col;
				success = true;
			}
		} else {
			reset();
			return false;
		}
	}
	*c = lastTry.col;
	*r = lastTry.row;
	successful = false;

	return true;
}
