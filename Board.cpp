#include "Board.hpp"

#include <random>

using namespace std;

Board::Board(int size)
{
	Board::size = size;

	tiles = new Tile * [size];
	for (int i = 0; i < size; i++)
		tiles[i] = new Tile[size];

	history = new Tile * *[size];
	for (int i = 0; i < size; i++)
	{
		history[i] = new Tile * [size];
		for (int j = 0; j < size; j++) {
			history[i][j] = new Tile();
		}
	}
}

Board::~Board()
{
	for (int i = 0; i < size; i++) {
		delete[] tiles[i];
	}
	delete[] tiles;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++) {
			delete history[i][j];
		}

		delete[] history[i];
	}
	delete[] history;
}

int Board::GetSize()
{
	return size;
}

void Board::AddRandomTile(int size)
{
	int i, j, value;

	while (true)
	{
		i = rand() % size;
		j = rand() % size;

		if (tiles[i][j].IsEmpty()) {
			break;
		}
	}

	value = (rand() % 10 == 0) ? 4 : 2;
	tiles[i][j].SetValue(value);
}

int Board::MoveOrMergeTile(int direction, int i, int j)
{
	int i1 = i, j1 = j;

	switch (direction)
	{
	case 0: i1--; break;	//вверх
	case 1: j1--; break;	//влево
	case 2: i1++; break;	//вниз
	case 3: j1++; break;	//вправо
	}

	if (tiles[i1][j1].IsEmpty())
	{
		tiles[i1][j1] = tiles[i][j];
		tiles[i1][j1].SetMergeFlag(tiles[i][j].GetMergeFlag());
		tiles[i][j].SetValue(0);
		tiles[i][j].SetMergeFlag(false);

		return 0;
	}
	else if (tiles[i][j].GetValue() == tiles[i1][j1].GetValue() &&
		!tiles[i][j].GetMergeFlag() && !tiles[i1][j1].GetMergeFlag())
	{
		tiles[i1][j1].SetValue(tiles[i1][j1].GetValue() * 2);
		tiles[i1][j1].SetMergeFlag(true);

		tiles[i][j].SetValue(0);

		return tiles[i1][j1].GetValue();
	}
	else {
		return 0;
	}
}