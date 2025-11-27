using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Game2048C_
{
    internal class GameManager
    {
        private Board board;
        private int score;
        private int aldScore;
        private int bestScore;
        private bool canCancelMove;
        private bool isWin;

        public GameManager(int size)
        {
            board = new Board(size);

            score = 0;
            aldScore = 0;
            canCancelMove = false;
            isWin = false;

            string fileName = $"Data{size}.txt";

            if (File.Exists(fileName))
            {
                using (var file = new StreamReader(fileName))
                {
                    int.TryParse(file.ReadLine(), out bestScore);
                }
            }
            else
            {
                bestScore = 0;
            }

            board.AddRandomTile(size);
        }

        public int GetValueOfTile(int i, int j)
        {
            return board.GetValueOfTile(i, j);
        }

        public int GetSize()
        {
            return board.GetSize();
        }

        public int GetScore()
        {
            return score;
        }

        public int GetBestScore()
        {
            return bestScore;
        }

        public bool CanCancelMove()
        {
            return canCancelMove;
        }

        public bool CheckGameOver()
        {
            int size = board.GetSize();

            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    if (board.IsEmptyTile(i, j))
                    {
                        return false;
                    }
                }
            }

            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size - 1; j++)
                {
                    if (board.GetValueOfTile(i, j) == GetValueOfTile(i, j + 1))
                    {
                        return false;
                    }
                }
            }

            for (int i = 0; i < size - 1; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    if (board.GetValueOfTile(i, j) == board.GetValueOfTile(i + 1, j))
                    {
                        return false;
                    }
                }
            }

            return true;
        }

        public bool CheckWin()
        {
            int size = board.GetSize();

            if (isWin)
                return false;

            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    if (board.GetValueOfTile(i, j) >= 2048)
                    {
                        isWin = true;
                        return true;
                    }
                }
            }

            return false;
        }

        public bool CanMoveOrMerge(int direction)
        {
            int size = board.GetSize();

            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    if (board.IsEmptyTile(i, j))
                    {
                        continue;
                    }

                    int i1 = i;
                    int j1 = j;

                    switch (direction)
                    {
                        case 0: i1--; break; // вверх
                        case 1: j1--; break; // влево
                        case 2: i1++; break; // вниз
                        case 3: j1++; break; // вправо
                    }

                    if (i1 < 0 || j1 < 0 || i1 >= size || j1 >= size)
                        continue;

                    if (board.IsEmptyTile(i1, j1))
                        return true;

                    if (board.GetValueOfTile(i1, j1) == board.GetValueOfTile(i, j))
                        return true;
                }
            }

            return false;
        }

        public void MoveAllTiles(int direction)
        {
            int size = board.GetSize();

            int i_min = 0, i_step = 1;
            int j_min = 0, j_step = 1;

            switch (direction)
            {
                case 0: i_min = 1; break;                       //вверх 
                case 1: j_min = 1; break;                       //влево 
                case 2: i_min = size - 2; i_step = -1; break;   //вниз 
                case 3: j_min = size - 2; j_step = -1; break;	//вправо
            }

            for (int t = 0; t < size; t++)
            {
                for (int i = i_min; i >= 0 && i < size; i += i_step)
                {
                    for (int j = j_min; j >= 0 && j < size; j += j_step)
                    {
                        score += board.MoveOrMergeTile(direction, i, j);
                    }
                }
            }

            if (score > bestScore)
                bestScore = score;

            for (int i = 0; i < size; i++)
                for (int j = 0; j < size; j++)
                    board.SetMergeFlagOfTile(i, j, false);

            board.AddRandomTile(size);
        }

        public void SaveHistory()
        {
            int size = board.GetSize();

            board.SaveHistory();

            aldScore = score;
            canCancelMove = true;
        }

        public void CancelMove()
        {
            board.CancelMove();

            score = aldScore;
            canCancelMove = false;
        }

        public bool LoadDataFromFile()
        {
            int size = board.GetSize();

            string fileName = $"Data{size}.txt";

            if (!File.Exists(fileName))
            {
                return false;
            }

            using (var file = new StreamReader(fileName))
            {
                int.TryParse(file.ReadLine(), out bestScore);
                int.TryParse(file.ReadLine(), out score);

                for (int i = 0; i < size; i++)
                {
                    string? line = file.ReadLine();
                    if (line == null)
                        return false;

                    string[] vals = line.Split(' ');

                    for (int j = 0; j < size; j++)
                    {
                        int value = int.Parse(vals[j]);
                        board.SetValueOfTile(i, j, value);
                        board.SetMergeFlagOfTile(i, j, false);
                    }
                }
            }

            return true;
        }

        public void SaveDataToFile()
        {
            int size = board.GetSize();

            string fileName = $"Data{size}.txt";

            using (var file = new StreamWriter(fileName))
            {
                file.WriteLine(bestScore);
                file.WriteLine(score);

                for (int i = 0; i < size; i++)
                {
                    for (int j = 0; j < size; j++)
                        file.Write(board.GetValueOfTile(i, j) + " ");

                    file.WriteLine();
                }
            }
        }
    }
}
