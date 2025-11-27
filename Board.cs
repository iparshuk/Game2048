using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Game2048C_
{
    public class Board
    {
        private int size;
        private Tile[,] tiles;
        private Tile[,] history;

        public Board(int size)
        {
            this.size = size;

            tiles = new Tile[size, size];
            history = new Tile[size, size];

            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    tiles[i, j] = new Tile();
                    history[i, j] = new Tile();
                }
            }
        }

        public void SetValueOfTile(int i, int j, int value)
        {
            tiles[i, j].SetValue(value);
        }

        public void SetMergeFlagOfTile(int i, int j, bool merged)
        {
            tiles[i, j].SetMergeFlag(merged);
        }

        public int GetSize()
        {
            return size;
        }

        public int GetValueOfTile (int i, int j)
        {
            return tiles[i, j].GetValue();
        }

        public bool IsEmptyTile(int i, int j)
        {
            return tiles[i, j].IsEmpty();
        }

        public void AddRandomTile(int size)
        {
            int i, j;

            Random rnd = new Random();

            while (true)
            {
                i = rnd.Next(size);
                j = rnd.Next(size);

                if (tiles[i, j].IsEmpty())
                    break;
            }

            int value = (rnd.Next(10) == 0) ? 4 : 2;
            tiles[i, j].SetValue(value);
        }

        public int MoveOrMergeTile(int direction, int i, int j)
        {
            int i1 = i, j1 = j;

            switch (direction)
            {
                case 0: i1--; break;    //вверх
                case 1: j1--; break;    //влево
                case 2: i1++; break;    //вниз
                case 3: j1++; break;	//вправо
            }

            if (tiles[i1, j1].IsEmpty())
            {
                tiles[i1, j1].CopyTile(tiles[i, j]);
                tiles[i, j].Clear();

                return 0;
            }
            else if (tiles[i, j].GetValue() == tiles[i1, j1].GetValue() &&
                     !tiles[i, j].GetMergeFlag() && !tiles[i1, j1].GetMergeFlag())
            {
                tiles[i1, j1].SetValue(tiles[i1, j1].GetValue() * 2);
                tiles[i1, j1].SetMergeFlag(true);

                tiles[i, j].Clear();

                return tiles[i1, j1].GetValue();
            }
            else {
                return 0;
            }
        }

        public void SaveHistory()
        {
            for (int i = 0; i < size; i++)
                for (int j = 0; j < size; j++)
                    history[i, j].CopyTile(tiles[i, j]);
        }

        public void CancelMove()
        {
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    tiles[i, j].CopyTile(history[i, j]);
                }
            }
        }
    }
}