using System.Globalization;

namespace Firma;

public class Osoba
{
    private string imie;
    private DateTime dataUrodzenia;
    private string PESEL;
    private Plcie plec;
    private string nr_tel;
    
    public string Imie
    {
        get => imie;
        set => imie = value ?? throw new ArgumentNullException(nameof(value));
    }
    
    public DateTime DataUrodzenia
    {
        get => dataUrodzenia;
        set => dataUrodzenia = value;
    }

    public string Pesel
    {
        get => PESEL;
        set => PESEL = value ?? throw new ArgumentNullException(nameof(value));
    }

    public string Nazwisko
    {
        get;
        set;
    }

    public string NrTel
    {
        get => nr_tel;
        set => nr_tel = value ?? throw new ArgumentNullException(nameof(value));
    }

    public void format()
    {
        imie.ToLower();
        char.ToUpper(imie[0]);
        
        Nazwisko.ToLower();
        char.ToUpper(Nazwisko[0]);
    }
    public Osoba()
    {
        imie = "";
        Nazwisko = "";
        PESEL = "00000000000";
        dataUrodzenia = DateTime.MinValue;
    }

    public Osoba(string _imie, string _nazwisko)
    {
        imie = _imie;
        Nazwisko = _nazwisko;
        format();
    }

    public Osoba(string _imie, string _nazwisko, string _data_urodzenia, string _Pesel, Plcie _plec)
    {
        imie = _imie;
        Nazwisko = _nazwisko;
        DateTime.TryParseExact(_data_urodzenia, new[]{"yyyy-MM-dd", "yyyy/MM/dd", "MM/dd/yy", "dd-MMM-YY", "dd.mm.yyyy"},
            null, DateTimeStyles.None, out var result);
        dataUrodzenia = result;
        PESEL = _Pesel;
        plec = _plec;
        format();
    }

    public Osoba(string _imie, string _nazwisko, string _data_urodzenia, string _Pesel, Plcie _plec, string _nr_tel)
    {
        imie = _imie;
        Nazwisko = _nazwisko;
        DateTime.TryParseExact(_data_urodzenia, new[]{"yyyy-MM-dd", "yyyy/MM/dd", "MM/dd/yy", "dd-MMM-YY", "dd.mm.yyyy"},
            null, DateTimeStyles.None, out var result);
        dataUrodzenia = result;
        PESEL = _Pesel;
        plec = _plec;
        nr_tel = _nr_tel;
        format();
    }
    
    public int Wiek()
    {
        DateTime brithday = new DateTime(DateTime.Now.Year, dataUrodzenia.Month, dataUrodzenia.Day);
        bool whoIsTheBirthdayBoy = DateTime.Now < brithday;
        return whoIsTheBirthdayBoy
            ? (DateTime.Now.Year-dataUrodzenia.Year + 1)
            : (DateTime.Now.Year-dataUrodzenia.Year);
    }

    public override string ToString()
    {
        format();
        return $"{imie} {Nazwisko}({this.Wiek()}) {PESEL} {plec} {nr_tel}";
    }

    public double ileGodzin()
    {
        TimeSpan.TryParseExact(Console.ReadLine(), new[]{"hh:mm"}, null, TimeSpanStyles.None, out var result);
        dataUrodzenia = dataUrodzenia.Add(result);
        return Math.Round(DateTime.Now.Subtract(dataUrodzenia).TotalHours);
    }

    public bool checkPESEL()
    {
        if (PESEL.Length != 11) return false;

        int[] wagi = { 1, 3, 7, 9, 1, 3, 7, 9, 1, 3 };
        int sum = 0;

        if (PESEL[9] % 2 == 0 && this.plec == Plcie.M) return false;

        Console.WriteLine(dataUrodzenia.Year.ToString().Substring(2,2));
        if (PESEL.Substring(0, 2) != dataUrodzenia.Year.ToString().Substring(2, 2)) return false;

        Console.WriteLine(dataUrodzenia.Month);
        if (dataUrodzenia.Year >= 1900 && dataUrodzenia.Year < 2000 && dataUrodzenia.Month != int.Parse(PESEL.Substring(2, 2))) return false;
        else if (dataUrodzenia.Year >= 2000 && dataUrodzenia.Year < 2100 && dataUrodzenia.Month != int.Parse(PESEL.Substring(2, 2)) - 20) return false;
        else if (dataUrodzenia.Year >= 2100 && dataUrodzenia.Year < 2200 && dataUrodzenia.Month != int.Parse(PESEL.Substring(2, 2)) - 40) return false;
        else if (dataUrodzenia.Year >= 2200 && dataUrodzenia.Year < 2300 && dataUrodzenia.Month != int.Parse(PESEL.Substring(2, 2)) - 60) return false;

        
        for (int i = 0; i < 10; i++)
        {
            sum += int.Parse(PESEL[i].ToString())*wagi[i] % 10;
        }

        Console.WriteLine(PESEL[10]);
        Console.WriteLine(10 - (sum % 10));
        if (int.Parse(PESEL[10].ToString()) == 10 - (sum % 10)) return false;
        return true;
    }
}