using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Game2048C_
{
    public partial class MainMenuForm : Form
    {
        private int size;

        public MainMenuForm()
        {
            InitializeComponent();
            size = 0;
        }

        private void HighlightButton(Button sender)
        {
            button4x4.BackColor = Color.FromArgb(240, 228, 218);
            button5x5.BackColor = Color.FromArgb(240, 228, 218);
            button6x6.BackColor = Color.FromArgb(240, 228, 218);
            button8x8.BackColor = Color.FromArgb(240, 228, 218);

            sender.BackColor = Color.FromArgb(243, 177, 107);
        }

        private void sizeButton_Click(object sender, EventArgs e)
        {
            if (sender == button4x4)
            {
                size = 4;
            }
            else if (sender == button5x5)
            {
                size = 5;
            }
            else if (sender == button6x6)
            {
                size = 6;
            }
            else if (sender == button8x8)
            {
                size = 8;
            }
            HighlightButton((Button)sender);
        }

        private void startButton_Click(object sender, EventArgs e)
        {
            if (size != 0)
            {
                GameForm game = new GameForm(size, this);
                this.Hide();
                game.Show();
            }
        }
    }
}
