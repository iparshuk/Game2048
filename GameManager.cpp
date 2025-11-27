#include "GameManager.hpp"

#include <string>
#include <fstream>

using namespace std;

GameManager::GameManager(int size) : board(size)
{
	score = 0;
	aldScore = 0;
	canCancelMove = false;
	isWin = false;

	string fileName = "Data" + to_string(size) + ".txt";
	ifstream file(fileName);
	if (file.is_open()) {
		file >> bestScore;
		file.close();
	}
	else {
		bestScore = 0;
	}

	board.AddRandomTile(size);
}

int GameManager::GetValueOfTile(int i, int j)
{
	return board.tiles[i][j].GetValue();
}

int GameManager::GetSize()
{
	return board.GetSize();
}

int GameManager::GetScore()
{
	return score;
}

int GameManager::GetBestScore()
{
	return bestScore;
}

bool GameManager::CanCancelMove()
{
	return canCancelMove;
}

bool GameManager::CheckGameOver()
{
	int size = board.size;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
		{
			if (board.tiles[i][j].IsEmpty()) {
				return false;
			}
		}
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - 1; j++)
		{
			if (board.tiles[i][j].GetValue() == board.tiles[i][j + 1].GetValue()) {
				return false;
			}
		}
	}

	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size; j++)
		{
			if (board.tiles[i][j].GetValue() == board.tiles[i + 1][j].GetValue()) {
				return false;
			}
		}
	}

	return true;
}

bool GameManager::CheckWin()
{
	int size = board.size;

	if (isWin) {
		return false;
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (board.tiles[i][j].GetValue() >= 2048) {
				isWin = true;
				return true;
			}
		}
	}

	return false;
}

bool GameManager::CanMoveOrMerge(int direction)
{
	int size = board.size;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
		{
			int i1 = i, j1 = j;

			switch (direction)
			{
			case 0: i1--; break; // вверх
			case 1: j1--; break; // влево
			case 2: i1++; break; // вниз
			case 3: j1++; break; // вправо
			}

			if (board.tiles[i][j].IsEmpty()) {
				continue;
			}

			if (i1 < 0 || j1 < 0 || i1 >= size || j1 >= size) {
				continue;
			}

			if (board.tiles[i1][j1].IsEmpty()) {
				return true;
			}

			if (board.tiles[i1][j1].GetValue() == board.tiles[i][j].GetValue()) {
				return true;
			}
		}
	}

	return false;
}

void GameManager::MoveAllTiles(int direction)
{
	int size = board.size;
	int i_min = 0, i_step = 1;
	int j_min = 0, j_step = 1;

	switch (direction)
	{
	case 0: i_min = 1; break;						//вверх 
	case 1: j_min = 1; break;						//влево 
	case 2: i_min = size - 2; i_step = -1; break; 	//вниз 
	case 3: j_min = size - 2; j_step = -1; break;	//вправо
	}

	for (int t = 0; t < size; t++) {
		for (int i = i_min; i >= 0 && i < size; i += i_step) {
			for (int j = j_min; j >= 0 && j < size; j += j_step)
			{
				score += board.MoveOrMergeTile(direction, i, j);
			}
		}
	}
	if (score > bestScore) {
		bestScore = score;
	}


	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
		{
			board.tiles[i][j].SetMergeFlag(false);
		}
	}

	board.AddRandomTile(size);
}

void GameManager::SaveHistory()
{
	int size = board.size;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
		{
			*board.history[i][j] = board.tiles[i][j];
		}
	}

	aldScore = score;

	canCancelMove = true;
}

void GameManager::CancelMove()
{
	int size = board.size;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
		{
			board.tiles[i][j] = *board.history[i][j];
		}
	}

	score = aldScore;

	canCancelMove = false;
}

bool GameManager::LoadDataFromFile()
{
	int size = board.size;
	string fileName = "Data" + to_string(size) + ".txt";

	ifstream file(fileName);
	if (!file.is_open()) {
		return false;
	}

	file >> bestScore;
	file >> score;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
		{
			int value;
			file >> value;
			board.tiles[i][j].SetValue(value);
			board.tiles[i][j].SetMergeFlag(false);
		}
	}

	file.close();
	return true;
}

void GameManager::SaveDataToFile()
{
	int size = board.size;
	string fileName = "Data" + to_string(size) + ".txt";

	ofstream file(fileName);

	file << bestScore << "\n";
	file << score << "\n";

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
		{
			file << board.tiles[i][j].GetValue() << " ";
		}
		file << "\n";
	}

	file.close();
}