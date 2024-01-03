namespace Firma;

public class KierownikZespołu: Osoba, ICloneable
{
    public int doswiadczenie;

    public KierownikZespołu(int doswiadczenie)
    {
        this.doswiadczenie = doswiadczenie;
    }

    public KierownikZespołu(string _imie, string _nazwisko, int doswiadczenie) : base(_imie, _nazwisko)
    {
        this.doswiadczenie = doswiadczenie;
    }

    public KierownikZespołu(string _imie, string _nazwisko, string _data_urodzenia, string _Pesel, Plcie _plec, int doswiadczenie) : base(_imie, _nazwisko, _data_urodzenia, _Pesel, _plec)
    {
        this.doswiadczenie = doswiadczenie;
    }

    public KierownikZespołu(string _imie, string _nazwisko, string _data_urodzenia, string _Pesel, Plcie _plec, string _nr_tel, int doswiadczenie) : base(_imie, _nazwisko, _data_urodzenia, _Pesel, _plec, _nr_tel)
    {
        this.doswiadczenie = doswiadczenie;
    }
    new public string ToString()
    {
        return $"{Imie} {Nazwisko} {DataUrodzenia:yyyy-mm-dd} {Pesel} {Plec} {doswiadczenie}";
    }

    public object Clone()
    {
        KierownikZespołu temp = (KierownikZespołu)this.MemberwiseClone();
        return temp;
    }
}