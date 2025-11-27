#pragma once

#include "Board.hpp"

class GameManager
{
private:
	Board board;
	int score;
	int aldScore;
	int bestScore;
	bool canCancelMove;
	bool isWin;
public:
	GameManager(int size);

	int GetValueOfTile(int i, int j);
	int GetSize();
	int GetScore();
	int GetBestScore();
	bool CanCancelMove();

	bool CheckGameOver();
	bool CheckWin();
	bool CanMoveOrMerge(int direction);

	void MoveAllTiles(int direction);
	void SaveHistory();
	void CancelMove();

	bool LoadDataFromFile();
	void SaveDataToFile();
};