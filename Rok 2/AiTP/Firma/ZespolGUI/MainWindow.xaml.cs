using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using Firma;

namespace ZespolGUI
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        
        public MainWindow()
        {
            Zespół zespol = new Zespół();
            InitializeComponent();
            zespol = (Zespół)Zespół.OdczytajXML("..\\..\\..\\..\\Firma\\bin\\Debug\\net7.0\\zespol.XML");
            lstMembers.ItemsSource = new ObservableCollection<CzłonekZespołu>(zespol.Członkowie);
            tbName.Text = zespol.Nazwa;
            tbManager.Text = zespol.Kierownik.ToString();
        }
    }
}
