#ifndef BS_STRATEGY_H
#define BS_STRATEGY_H

#include "coord.h"

class BS_Strategy {
public:
typedef enum {NOCHANCE, NOTLIKELY, MAYBE, LIKELY} chance_t;

typedef enum {NONE, UP, DOWN, LEFT, RIGHT} dir_t;

	// Constructor
	BS_Strategy() : up(MAYBE), 
			down(MAYBE), 
			left(MAYBE), 
			right(MAYBE),
			successful(true),
			last_dir(NONE) { }

	bool valid();
	void update(char c, char r);
	bool getMove(char *c, char *r);
	
private:
	void reset();
	void set(char c, char r);

	chance_t up, down, left, right;
	dir_t last_dir;
	bool successful;
	coord_t firstTry;
	coord_t lastTry;
};

#endif // BS_STRATEGY_H
