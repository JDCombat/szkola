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
            }
            if (_osoba is CzłonekZespołu)
            {
                tbPESEL.Text = osoba.Pesel;
                tbName.Text = osoba.Imie;
                tbSurname.Text = osoba.Nazwisko;
                tbDate.Text = osoba.DataUrodzenia.ToString("dd-MMM-yyyy");
                cbGender.Text = ((osoba.Plec) == Plcie.K) ? "Kobieta" : "Mężczyzna";
            }
        }

        private void bSave_Click(object sender, RoutedEventArgs e)
        {
            if (tbPESEL.Text != "" && tbName.Text != "" && tbSurname.Text != "")
            {
                _osoba.Pesel = tbPESEL.Text;
                _osoba.Imie = tbName.Text;
                _osoba.Nazwisko = tbSurname.Text;
                string[] fdate = { "yyyy-MM-dd", "yyyy/MM/dd", "MM/dd/yy", "dd-MMM-yy", "dd.MM.yyyy", "dd-MMM-yyyy"};
                var result = DateTime.TryParseExact(tbDate.Text, fdate, null, DateTimeStyles.None, out DateTime
                date);
                if (result)
                {
                    _osoba.DataUrodzenia = date;
                    _osoba.Plcie = (cbGender.Text == "kobieta") ? Plcie.K : Plcie.M;
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
                
            }
            DialogResult = true;
        }

        private void bCancel_Click(object sender, RoutedEventArgs e)
        {
            DialogResult = false;
        }
    }
}
