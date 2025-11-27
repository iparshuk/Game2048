using System.Resources;

namespace Game2048C_
{
    partial class GameForm
    {
        private System.ComponentModel.IContainer components = null;
        private System.Windows.Forms.Button buttonBack;
        private System.Windows.Forms.Button buttonRestart;
        private System.Windows.Forms.Button buttonHome;
        private System.Windows.Forms.Label labelActualScore;
        private System.Windows.Forms.Label labelBestScore;
        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel1;

        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(GameForm));
            buttonBack = new Button();
            buttonRestart = new Button();
            buttonHome = new Button();
            tableLayoutPanel1 = new TableLayoutPanel();
            labelActualScore = new Label();
            labelBestScore = new Label();
            SuspendLayout();
            // 
            // buttonBack
            // 
            buttonBack.BackgroundImage = (Image)resources.GetObject("buttonBack.BackgroundImage");
            buttonBack.BackgroundImageLayout = ImageLayout.Stretch;
            buttonBack.Location = new Point(145, 14);
            buttonBack.Margin = new Padding(4, 3, 4, 3);
            buttonBack.Name = "buttonBack";
            buttonBack.Size = new Size(58, 58);
            buttonBack.TabIndex = 0;
            buttonBack.UseVisualStyleBackColor = true;
            buttonBack.Click += buttonBack_Click;
            // 
            // buttonRestart
            // 
            buttonRestart.BackgroundImage = (Image)resources.GetObject("buttonRestart.BackgroundImage");
            buttonRestart.BackgroundImageLayout = ImageLayout.Stretch;
            buttonRestart.Location = new Point(79, 14);
            buttonRestart.Margin = new Padding(4, 3, 4, 3);
            buttonRestart.Name = "buttonRestart";
            buttonRestart.Size = new Size(58, 58);
            buttonRestart.TabIndex = 1;
            buttonRestart.UseVisualStyleBackColor = true;
            buttonRestart.Click += buttonRestart_Click;
            // 
            // buttonHome
            // 
            buttonHome.BackgroundImage = (Image)resources.GetObject("buttonHome.BackgroundImage");
            buttonHome.BackgroundImageLayout = ImageLayout.Stretch;
            buttonHome.Location = new Point(14, 14);
            buttonHome.Margin = new Padding(4, 3, 4, 3);
            buttonHome.Name = "buttonHome";
            buttonHome.Size = new Size(58, 58);
            buttonHome.TabIndex = 2;
            buttonHome.UseVisualStyleBackColor = true;
            buttonHome.Click += buttonHome_Click;
            // 
            // tableLayoutPanel1
            // 
            tableLayoutPanel1.ColumnCount = 1;
            tableLayoutPanel1.ColumnStyles.Add(new ColumnStyle(SizeType.Absolute, 525F));
            tableLayoutPanel1.Location = new Point(0, 173);
            tableLayoutPanel1.Margin = new Padding(4, 3, 4, 3);
            tableLayoutPanel1.MaximumSize = new Size(525, 519);
            tableLayoutPanel1.MinimumSize = new Size(525, 519);
            tableLayoutPanel1.Name = "tableLayoutPanel1";
            tableLayoutPanel1.RowCount = 1;
            tableLayoutPanel1.RowStyles.Add(new RowStyle(SizeType.Absolute, 519F));
            tableLayoutPanel1.Size = new Size(525, 519);
            tableLayoutPanel1.TabIndex = 0;
            // 
            // labelActualScore
            // 
            labelActualScore.BackColor = Color.Khaki;
            labelActualScore.BorderStyle = BorderStyle.FixedSingle;
            labelActualScore.Font = new Font("Microsoft Sans Serif", 14F);
            labelActualScore.Location = new Point(210, 14);
            labelActualScore.Margin = new Padding(4, 0, 4, 0);
            labelActualScore.Name = "labelActualScore";
            labelActualScore.Size = new Size(146, 57);
            labelActualScore.TabIndex = 3;
            labelActualScore.Text = "СЧЁТ\r\n0";
            labelActualScore.TextAlign = ContentAlignment.MiddleCenter;
            // 
            // labelBestScore
            // 
            labelBestScore.BackColor = Color.Khaki;
            labelBestScore.BorderStyle = BorderStyle.FixedSingle;
            labelBestScore.Font = new Font("Microsoft Sans Serif", 14F);
            labelBestScore.Location = new Point(365, 14);
            labelBestScore.Margin = new Padding(4, 0, 4, 0);
            labelBestScore.Name = "labelBestScore";
            labelBestScore.Size = new Size(146, 57);
            labelBestScore.TabIndex = 4;
            labelBestScore.Text = "РЕКОРД\r\n0";
            labelBestScore.TextAlign = ContentAlignment.MiddleCenter;
            // 
            // GameForm
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            BackColor = Color.LemonChiffon;
            ClientSize = new Size(525, 692);
            Controls.Add(labelBestScore);
            Controls.Add(labelActualScore);
            Controls.Add(tableLayoutPanel1);
            Controls.Add(buttonHome);
            Controls.Add(buttonRestart);
            Controls.Add(buttonBack);
            FormBorderStyle = FormBorderStyle.FixedSingle;
            KeyPreview = true;
            Margin = new Padding(4, 3, 4, 3);
            Name = "GameForm";
            StartPosition = FormStartPosition.CenterScreen;
            Text = "2048";
            FormClosing += GameForm_FormClosing;
            KeyDown += GameForm_KeyDown;
            ResumeLayout(false);
        }

        #endregion
    }
}