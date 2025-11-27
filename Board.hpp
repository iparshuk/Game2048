#pragma once

#include "Tile.hpp"

class Board {
private:
	int size;
	Tile** tiles;
	Tile*** history;
public:
	Board(int size);
	~Board();

	int GetSize();
	void AddRandomTile(int size);
	int MoveOrMergeTile(int direction, int i, int j);

	friend class GameManager;
};