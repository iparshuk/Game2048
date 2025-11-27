namespace Game2048C_
{
    partial class MainMenuForm
    {
        private System.ComponentModel.IContainer components = null;
        private Button button4x4;
        private Button button5x5;
        private Button button6x6;
        private Button button8x8;
        private Button startButton;

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
            this.button4x4 = (new System.Windows.Forms.Button());
            this.button5x5 = (new System.Windows.Forms.Button());
            this.button6x6 = (new System.Windows.Forms.Button());
            this.button8x8 = (new System.Windows.Forms.Button());
            this.startButton = (new System.Windows.Forms.Button());
            this.SuspendLayout();
            // 
            // button4x4
            // 
            this.button4x4.Font = new System.Drawing.Font("Microsoft Sans Serif", 24F);
            this.button4x4.Location = new System.Drawing.Point(46, 63);
            this.button4x4.Name = "button4x4";
            this.button4x4.Size = new System.Drawing.Size(150, 50);
            this.button4x4.TabIndex = 0;
            this.button4x4.Text = "4x4";
            this.button4x4.UseVisualStyleBackColor = true;
            this.button4x4.Click += new System.EventHandler(this.sizeButton_Click);
            // 
            // button5x5
            // 
            this.button5x5.Font = new System.Drawing.Font("Microsoft Sans Serif", 24F);
            this.button5x5.Location = new System.Drawing.Point(234, 63);
            this.button5x5.Name = "button5x5";
            this.button5x5.Size = new System.Drawing.Size(150, 50);
            this.button5x5.TabIndex = 1;
            this.button5x5.Text = "5x5";
            this.button5x5.UseVisualStyleBackColor = true;
            this.button5x5.Click += new System.EventHandler(this.sizeButton_Click); ;
            // 
            // button6x6
            // 
            this.button6x6.Font = new System.Drawing.Font("Microsoft Sans Serif", 24F);
            this.button6x6.Location = new System.Drawing.Point(46, 134);
            this.button6x6.Name = "button6x6";
            this.button6x6.Size = new System.Drawing.Size(150, 50);
            this.button6x6.TabIndex = 2;
            this.button6x6.Text = "6x6";
            this.button6x6.UseVisualStyleBackColor = true;
            this.button6x6.Click += new System.EventHandler(this.sizeButton_Click);
            // 
            // button8x8
            // 
            this.button8x8.Font = new System.Drawing.Font("Microsoft Sans Serif", 24F);
            this.button8x8.Location = new System.Drawing.Point(234, 134);
            this.button8x8.Name = "button8x8";
            this.button8x8.Size = new System.Drawing.Size(150, 50);
            this.button8x8.TabIndex = 3;
            this.button8x8.Text = "8x8";
            this.button8x8.UseVisualStyleBackColor = true;
            this.button8x8.Click += new System.EventHandler(this.sizeButton_Click);
            // 
            // startButton
            // 
            this.startButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 24F);
            this.startButton.Location = new System.Drawing.Point(141, 244);
            this.startButton.Name = "startButton";
            this.startButton.Size = new System.Drawing.Size(150, 50);
            this.startButton.TabIndex = 4;
            this.startButton.Text = "Играть";
            this.startButton.UseVisualStyleBackColor = true;
            this.startButton.Click += new System.EventHandler(this.startButton_Click);
            // 
            // MainMenuForm
            // 
            this.BackColor = System.Drawing.Color.LemonChiffon;
            this.ClientSize = new System.Drawing.Size(434, 561);
            this.Controls.Add(this.startButton);
            this.Controls.Add(this.button8x8);
            this.Controls.Add(this.button6x6);
            this.Controls.Add(this.button5x5);
            this.Controls.Add(this.button4x4);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Name = "MainMenuForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "2048";
            this.ResumeLayout(false);

        }

        #endregion
    }
}