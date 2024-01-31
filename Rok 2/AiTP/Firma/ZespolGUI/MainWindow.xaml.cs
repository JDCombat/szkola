using System;
using System.Collections;
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
        public Zespół zespol;
        public bool changed;
        public MainWindow()
        {
            InitializeComponent();
            Microsoft.Win32.OpenFileDialog dlg = new Microsoft.Win32.OpenFileDialog();
            dlg.Filter = "XML Files (*.xml)|*.xml";
            dlg.DefaultExt = "xml";
            dlg.AddExtension = true;
            dlg.FileName = "zespol.xml";
            Nullable<bool> result = dlg.ShowDialog();
            if (result == true)
            {
                zespol = Zespół.OdczytajXML(dlg.FileName);
                lstMembers.ItemsSource = new ObservableCollection<CzłonekZespołu>(zespol.Członkowie);
                tbName.Text = zespol.Nazwa;
                tbManager.Text = zespol.Kierownik.ToString();
            }
            changed = false;
        }

        private void bChange_Click(object sender, RoutedEventArgs e)
        {
            OsobaWindow okno = new OsobaWindow(zespol.Kierownik);
            okno.ShowDialog();
            tbManager.Text = zespol.Kierownik.ToString();
            changed = true;
        }

        private void bAdd_Click(object sender, RoutedEventArgs e)
        {
            CzłonekZespołu cz = new CzłonekZespołu();
            OsobaWindow okno = new OsobaWindow(cz);
            okno.ShowDialog();
            if (okno.DialogResult == true)
            {
                zespol.dodajCzłonka(cz);
                lstMembers.ItemsSource = new ObservableCollection<CzłonekZespołu>(zespol.Członkowie);
                changed = true;
            }
        }

        private void bRemove_Click(object sender, RoutedEventArgs e)
        {
            int zaznaczony = lstMembers.SelectedIndex;
            zespol.Członkowie.RemoveAt(zaznaczony);
            lstMembers.ItemsSource = new ObservableCollection<CzłonekZespołu>(zespol.Członkowie);
            changed = true;
        }
        private void MenuZapisz_Click(object sender, RoutedEventArgs e)
        {
            Microsoft.Win32.SaveFileDialog dlg = new Microsoft.Win32.SaveFileDialog();
            dlg.Filter = "XML Files (*.xml)|*.xml";
            dlg.DefaultExt = "xml";
            dlg.AddExtension = true;
            dlg.FileName = "zespol";
            Nullable<bool> result = dlg.ShowDialog();
            if (result == true)
            {
                string filename = dlg.FileName;
                zespol.Nazwa = tbName.Text;
                Zespół.ZapiszXML(filename, zespol);
                changed = false;
            }
        }
        private void MenuOtworz_Click(object sender, RoutedEventArgs e)
        {
            Microsoft.Win32.OpenFileDialog dlg = new Microsoft.Win32.OpenFileDialog();
            dlg.Filter = "XML Files (*.xml)|*.xml";
            dlg.DefaultExt = "xml";
            dlg.AddExtension = true;
            dlg.FileName = "zespol.xml";
            Nullable<bool> result = dlg.ShowDialog();
            if (result == true)
            {
                zespol = Zespół.OdczytajXML(dlg.FileName);
                lstMembers.ItemsSource = new ObservableCollection<CzłonekZespołu>(zespol.Członkowie);
                tbName.Text = zespol.Nazwa;
                tbManager.Text = zespol.Kierownik.ToString();
                changed = false;
            }
        }



        private void MenuWyjdz_Click(object sender, RoutedEventArgs e)
        {
            Close();
        }

        private void tbName_TextChanged(object sender, TextChangedEventArgs e)
        {
            changed = true;
        }

        private void tbManager_TextChanged(object sender, TextChangedEventArgs e)
        {
            changed = true;
        }

        private void Window_Closing(object sender, System.ComponentModel.CancelEventArgs e)
        {
            if (changed)
            {
                var result = MessageBox.Show("Zapisać plik?", "Zapisać plik?", MessageBoxButton.YesNo, MessageBoxImage.Question);
                if (result == MessageBoxResult.Yes)
                {
                    MenuZapisz_Click(sender, null);
                }
            }
        }

        private void bChangeMember_Click(object sender, RoutedEventArgs e)
        {
            var index = lstMembers.SelectedIndex;
            if (index == -1)
            {
                MessageBox.Show("Zaznacz członka", "Błąd", MessageBoxButton.OK, MessageBoxImage.Error);
            }
            else
            {
                var cz = zespol.Członkowie.ElementAt(index);
                OsobaWindow okno = new OsobaWindow(cz);

                var result = okno.ShowDialog();
                if (result == true)
                {
                    zespol.Członkowie[index] = cz;
                    lstMembers.ItemsSource = new ObservableCollection<CzłonekZespołu>(zespol.Członkowie);
                }
                changed = true;
            }
        }

        private void bSort_Click(object sender, RoutedEventArgs e)
        {
            zespol.sortujPoPESEL();
            lstMembers.ItemsSource = new ObservableCollection<CzłonekZespołu>(zespol.Członkowie);
        }
    }
}
