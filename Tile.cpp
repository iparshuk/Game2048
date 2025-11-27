#include "Tile.hpp"

Tile::Tile()
{
	value = 0;
	merged = false;
}

void Tile::SetValue(int value)
{
	Tile::value = value;
}

void Tile::SetMergeFlag(bool merged)
{
	Tile::merged = merged;
}

int Tile::GetValue()
{
	return value;
}

bool Tile::GetMergeFlag()
{
	return Tile::merged;
}

bool Tile::IsEmpty()
{
	return value == 0;
}