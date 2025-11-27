using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Game2048C_
{
    public class Tile
    {
        private int value;
        private bool merged;

        public Tile()
        {
            value = 0;
            merged = false;
        }

        public void SetValue(int value)
        {
            this.value = value;
        }

        public void SetMergeFlag(bool merged)
        {
            this.merged = merged;
        }

        public int GetValue()
        {
            return value;
        }

        public bool GetMergeFlag()
        {
            return merged;
        }

        public bool IsEmpty()
        {
            return value == 0;
        }

        public void CopyTile(Tile other)
        {
            this.value = other.value;
            this.merged = other.merged;
        }

        public void Clear()
        {
            this.value = 0;
            this.merged = false;
        }
    }
}
