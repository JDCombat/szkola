using System.Globalization;

namespace Firma;
[Serializable()]

public class CzłonekZespołu: Osoba, ICloneable, IComparable<CzłonekZespołu>
{
    public DateTime dataZapisu;
    public string funkcja;

    public CzłonekZespołu()
    {
        dataZapisu = DateTime.MinValue;
        funkcja = "";
    }

    public CzłonekZespołu(string _imie, string _nazwisko, string _dataZapisu, string _funkcja) : base(_imie, _nazwisko)
    {
        DateTime.TryParseExact(_dataZapisu, new[]{"yyyy-MM-dd", "yyyy/MM/dd", "MM/dd/yy", "dd-MMM-YY", "dd.mm.yyyy"},
            null, DateTimeStyles.None, out var result);
        dataZapisu = result;
        funkcja = _funkcja;
    }

    public CzłonekZespołu(string _imie, string _nazwisko, string _data_urodzenia, string _Pesel, Plcie _plec, string _dataZapisu, string funkcja) : base(_imie, _nazwisko, _data_urodzenia, _Pesel, _plec)
    {
        DateTime.TryParseExact(_dataZapisu, new[]{"yyyy-MM-dd", "yyyy/MM/dd", "MM/dd/yy", "dd-MMM-YY", "dd.mm.yyyy"},
            null, DateTimeStyles.None, out var result);
        dataZapisu = result;
        this.funkcja = funkcja;
    }

    public CzłonekZespołu(string _imie, string _nazwisko, string _data_urodzenia, string _Pesel, Plcie _plec, string _nr_tel, string _dataZapisu, string funkcja) : base(_imie, _nazwisko, _data_urodzenia, _Pesel, _plec, _nr_tel)
    {
        DateTime.TryParseExact(_dataZapisu, new[]{"yyyy-MM-dd", "yyyy/MM/dd", "MM/dd/yy", "dd-MMM-YY", "dd.mm.yyyy"},
            null, DateTimeStyles.None, out var result);
        dataZapisu = result;
        this.funkcja = funkcja;
    }

    public new string ToString()
    {
        return $"{Imie} {Nazwisko} {DataUrodzenia:yyyy-mm-dd} {Pesel} {Plec} {funkcja} ({dataZapisu:dd-MMM-yyyy})";
    }

    public object Clone()
    {
        CzłonekZespołu temp = (CzłonekZespołu) this.MemberwiseClone();
        return temp;
    }

    public int CompareTo(CzłonekZespołu second)
    {
        if (this.Nazwisko == second.Nazwisko)
        {
            return String.Compare(this.Imie, second.Imie, StringComparison.Ordinal);
        }
        return string.Compare(this.Nazwisko, second.Nazwisko, StringComparison.Ordinal);
    }
}