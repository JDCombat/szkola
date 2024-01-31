using Firma;
using System;
using System.Collections.Generic;
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
using System.Windows.Shapes;
using Firma;
using System.Globalization;
using System.Linq.Expressions;

namespace ZespolGUI
{
    /// <summary>
    /// Interaction logic for OsobaWindow.xaml
    /// </summary>
    public partial class OsobaWindow : Window
    {
        public Osoba _osoba;
        public OsobaWindow()
        {
            InitializeComponent();
        }
        public OsobaWindow(Osoba osoba) : this()
        {
            _osoba = osoba;
            if (_osoba is KierownikZespołu)
            {
                tbPESEL.Text = osoba.Pesel;
                tbName.Text = osoba.Imie;
                tbSurname.Text = osoba.Nazwisko;
                tbDate.Text = osoba.DataUrodzenia.ToString("dd-MMM-yyyy");
                cbGender.Text = ((osoba.Plec) == Plcie.K) ? "Kobieta" : "Mężczyzna";
                lChange.Content = "Doświadczenie";
                tbChange.Text = ((KierownikZespołu)osoba).doswiadczenie.ToString();
            }
            if (_osoba is CzłonekZespołu)
            {
                tbPESEL.Text = osoba.Pesel;
                tbName.Text = osoba.Imie;
                tbSurname.Text = osoba.Nazwisko;
                tbDate.Text = osoba.DataUrodzenia.ToString("dd-MMM-yyyy");
                cbGender.Text = ((osoba.Plec) == Plcie.K) ? "Kobieta" : "Mężczyzna";
                lChange.Content = "Funkcja";
                tbChange.Text = ((CzłonekZespołu)osoba).funkcja;
            }
        }

        private void bSave_Click(object sender, RoutedEventArgs e)
        {
            if (tbPESEL.Text != "" && tbName.Text != "" && tbSurname.Text != "")
            {
                _osoba.Pesel = tbPESEL.Text;
                _osoba.Imie = tbName.Text;
                _osoba.Nazwisko = tbSurname.Text;
                _osoba.Plcie = (cbGender.Text == "Kobieta") ? Plcie.K : Plcie.M;
                string[] fdate = { "yyyy-MM-dd", "yyyy/MM/dd", "MM/dd/yy", "dd-MMM-yy", "dd.MM.yyyy", "dd-MMM-yyyy"};
                var result = DateTime.TryParseExact(tbDate.Text, fdate, null, DateTimeStyles.None, out DateTime
                date);
                if (result == true)
                {
                    _osoba.DataUrodzenia = date;
                }
                else
                {
                    try {
                        throw new Exception("Data się nie zgadza");
                    }
                    catch(Exception ex) { 
                        var message = MessageBox.Show("Data się nie zgadza", "Błąd", MessageBoxButton.OK, MessageBoxImage.Error);
                    }
                }
                if (_osoba is KierownikZespołu)
                {
                    ((KierownikZespołu)_osoba).doswiadczenie = int.Parse(tbChange.Text);
                }
                else if(_osoba is CzłonekZespołu)
                {
                    ((CzłonekZespołu)_osoba).funkcja = tbChange.Text;
                }
            }
            DialogResult = true;
        }

        private void bCancel_Click(object sender, RoutedEventArgs e)
        {
            DialogResult = false;
        }
    }
}
