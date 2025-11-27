#pragma once

class Tile
{
private:
	int value;
	bool merged;
public:
	Tile();

	void SetValue(int value);
	void SetMergeFlag(bool merged);

	int GetValue();
	bool GetMergeFlag();

	bool IsEmpty();
};