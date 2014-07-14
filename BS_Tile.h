#ifndef BS_TILE_H
#define BS_TILE_H

class BS_Tile {
public:
	BS_Tile() : col(0), row(0) { }
	BS_Tile(char c, char r) : col(c), row(r) { }

	~BS_Tile() { }

	char getCol() {
		return col;
	}

	char getRow() {
		return row;
	}

	bool valid() {
		return col;
	}

private:
	char col, row;
};

#endif // BS_TILE_H
