namespace WindowsFormsApp1
{
    partial class FormularzPierwszy
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }

            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.lInfo = new System.Windows.Forms.Label();
            this.tbName = new System.Windows.Forms.TextBox();
            this.bNotes = new System.Windows.Forms.Button();
            this.lWelcum = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // lInfo
            // 
            this.lInfo.AutoSize = true;
            this.lInfo.Location = new System.Drawing.Point(335, 137);
            this.lInfo.Name = "lInfo";
            this.lInfo.Size = new System.Drawing.Size(39, 13);
            this.lInfo.TabIndex = 0;
            this.lInfo.Text = "gowno";
            // 
            // tbName
            // 
            this.tbName.Location = new System.Drawing.Point(310, 185);
            this.tbName.Name = "tbName";
            this.tbName.Size = new System.Drawing.Size(100, 20);
            this.tbName.TabIndex = 1;
            // 
            // bNotes
            // 
            this.bNotes.Location = new System.Drawing.Point(319, 238);
            this.bNotes.Name = "bNotes";
            this.bNotes.Size = new System.Drawing.Size(75, 23);
            this.bNotes.TabIndex = 2;
            this.bNotes.Text = "Enter";
            this.bNotes.UseVisualStyleBackColor = true;
            this.bNotes.Click += new System.EventHandler(this.bNotes_Click);
            // 
            // lWelcum
            // 
            this.lWelcum.AutoSize = true;
            this.lWelcum.Location = new System.Drawing.Point(335, 294);
            this.lWelcum.Name = "lWelcum";
            this.lWelcum.Size = new System.Drawing.Size(46, 13);
            this.lWelcum.TabIndex = 3;
            this.lWelcum.Text = "Welcum";
            // 
            // FormularzPierwszy
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.lWelcum);
            this.Controls.Add(this.bNotes);
            this.Controls.Add(this.tbName);
            this.Controls.Add(this.lInfo);
            this.Name = "FormularzPierwszy";
            this.Text = "Iteracja pierwsza";
            this.ResumeLayout(false);
            this.PerformLayout();
        }

        #endregion

        private System.Windows.Forms.Label lInfo;
        private System.Windows.Forms.TextBox tbName;
        private System.Windows.Forms.Button bNotes;
        private System.Windows.Forms.Label lWelcum;
    }
}