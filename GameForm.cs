using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Security.Policy;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Game2048C_
{
    public partial class GameForm : Form
    {
        private Form aldForm;
        private GameManager gameManager;
        private UserInteract userInteract = new UserInteract();

        public GameForm(int size, Form form)
        {
            InitializeComponent();

            gameManager = new GameManager(size);

            gameManager.LoadDataFromFile();
            CreateGrid(size);
            UpdateGrid();
            UpdateScore();

            gameManager.CheckWin();
            if (gameManager.CheckGameOver())
            {
                buttonRestart_Click(null, null);
            }

            aldForm = form;
        }

        public void CreateGrid(int size)
        {
            tableLayoutPanel1.RowStyles.Clear();
            tableLayoutPanel1.ColumnStyles.Clear();
            tableLayoutPanel1.Controls.Clear();

            tableLayoutPanel1.RowCount = size;
            tableLayoutPanel1.ColumnCount = size;

            for (int i = 0; i < size; i++)
            {
                tableLayoutPanel1.RowStyles.Add(new RowStyle(SizeType.Percent, 100f / size));
                tableLayoutPanel1.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, 100f / size));
            }

            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    Label lbl = new Label();
                    lbl.Dock = DockStyle.Fill;
                    lbl.Font = new Font("Arial", tableLayoutPanel1.Width / size * 0.2f, FontStyle.Bold);
                    lbl.TextAlign = ContentAlignment.MiddleCenter;
                    lbl.Margin = new Padding(0);
                    lbl.BorderStyle = BorderStyle.FixedSingle;

                    tableLayoutPanel1.Controls.Add(lbl, j, i);
                }
            }
        }

        public void MakeMove()
        {
            int direction = userInteract.GetDirection();

            if (gameManager.CanMoveOrMerge(direction))
            {
                gameManager.SaveHistory();
                gameManager.MoveAllTiles(direction);
                gameManager.SaveDataToFile();

                UpdateGrid();
                UpdateScore();

                buttonRestart_Click(null, null);
            }
        }

        public void UpdateGrid()
        {
            int size = gameManager.GetSize();

            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    Label lbl = (Label)tableLayoutPanel1.GetControlFromPosition(j, i);
                    int value = gameManager.GetValueOfTile(i, j);

                    lbl.Text = (value == 0) ? "" : value.ToString();
                    lbl.BackColor = GetTileColor(value);
                }
            }
        }

        public void UpdateScore()
        {
            labelActualScore.Text = "СЧЁТ\r\n" + gameManager.GetScore();
            labelBestScore.Text = "РЕКОРД\r\n" + gameManager.GetBestScore();
        }

        public Color GetTileColor(int value)
        {
            switch (value)
            {
                case 0: return Color.FromArgb(205, 193, 180);
                case 2: return Color.FromArgb(238, 228, 218);
                case 4: return Color.FromArgb(237, 224, 200);
                case 8: return Color.FromArgb(242, 177, 121);
                case 16: return Color.FromArgb(245, 149, 99);
                case 32: return Color.FromArgb(246, 124, 95);
                case 64: return Color.FromArgb(246, 94, 59);
                case 128: return Color.FromArgb(237, 207, 114);
                case 256: return Color.FromArgb(237, 204, 97);
                case 512: return Color.FromArgb(237, 200, 80);
                case 1024: return Color.FromArgb(237, 197, 63);
                case 2048: return Color.FromArgb(237, 194, 46);
                default: return Color.FromArgb(60, 58, 50);
            }
        }

        private void buttonHome_Click(object sender, EventArgs e)
        {
            aldForm.Show();
            this.Close();
        }

        private void buttonBack_Click(object sender, EventArgs e)
        {
            if (gameManager.CanCancelMove())
            {
                gameManager.CancelMove();
                gameManager.SaveDataToFile();

                UpdateGrid();
                UpdateScore();
            }
        }

        private void buttonRestart_Click(object sender, EventArgs e)
        {
            string message = "";

            if (sender == null && gameManager.CheckWin())
                message = userInteract.GetMessage('w');
            else if (sender == null && gameManager.CheckGameOver())
                message = userInteract.GetMessage('l');
            else if (sender != null)
                message = userInteract.GetMessage('r');

            if (message != "")
            {
                DialogResult result = MessageBox.Show(
                    message,
                    "Конец",
                    MessageBoxButtons.YesNo,
                    MessageBoxIcon.Question);

                if (result == DialogResult.Yes)
                {
                    int size = gameManager.GetSize();

                    gameManager = new GameManager(size);
                    gameManager.SaveDataToFile();

                    UpdateGrid();
                    UpdateScore();
                }
            }
        }

        private void GameForm_KeyDown(object sender, KeyEventArgs e)
        {
            int direction;

            switch (e.KeyCode)
            {
                case Keys.W: direction = 0; break;
                case Keys.A: direction = 1; break;
                case Keys.S: direction = 2; break;
                case Keys.D: direction = 3; break;
                default: return;
            }

            userInteract.SetDirection(direction);
            MakeMove();
        }

        private void GameForm_FormClosing(object sender, FormClosingEventArgs e)
        {
            if (!aldForm.Visible)
            {
                Application.Exit();
            }
        }
    }
}
