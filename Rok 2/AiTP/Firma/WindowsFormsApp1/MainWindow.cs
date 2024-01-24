using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class FormularzPierwszy : Form
    {
        public FormularzPierwszy()
        {
            InitializeComponent();
        }

        private void bNotes_Click(object sender, EventArgs e)
        {
            lWelcum.Text = $"Hell {tbName.Text}";
        }
    }
}