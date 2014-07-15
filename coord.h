#ifndef COORD_H
#define COORD_H

typedef struct coord_ {
	char col;
	char row;

	coord_() : col(0), row(0) { }

	coord_(char c, char r) : col(c), row(r) { }
} coord_t;

#endif // COORD_H
