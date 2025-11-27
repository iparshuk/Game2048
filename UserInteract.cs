using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Game2048C_
{
    public class UserInteract
    {
        private int direction;
        private string youWin;
        private string youLost;
        private string question;

        public UserInteract()
        {
            direction = -1;
            youWin = "Вы победили\n";
            youLost = "Вы проиграли\n";
            question = "Начать заново?";
        }

        public void SetDirection(int direction)
        {
            this.direction = direction;
        }

        public int GetDirection()
        {
            return direction;
        }

        public string GetMessage(char mess)
        {
            if (mess == 'w')
                return youWin + question;
            else if (mess == 'l')
                return youLost + question;
            else if (mess == 'r')
                return question;

            return string.Empty;
        }
    }
}
