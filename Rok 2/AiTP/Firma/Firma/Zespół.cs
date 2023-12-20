﻿using System.Text;

namespace Firma;

public class Zespół
{
    private int liczbaCzłonków;
    private string nazwa;
    private KierownikZespołu kierownik;
    private List<CzłonekZespołu> członkowie = new List<CzłonekZespołu>();

    public int LiczbaCzłonków
    {
        get => liczbaCzłonków;
        set => liczbaCzłonków = value;
    }

    public string Nazwa
    {
        get => nazwa;
        set => nazwa = value ?? throw new ArgumentNullException(nameof(value));
    }

    public KierownikZespołu Kierownik
    {
        get => kierownik;
        set => kierownik = value ?? throw new ArgumentNullException(nameof(value));
    }

    public Zespół()
    {
        nazwa = null;
        kierownik = null;
        członkowie = new List<CzłonekZespołu>(0);
    }

    public Zespół(string nazwa, KierownikZespołu kierownik)
    {
        this.nazwa = nazwa;
        this.kierownik = kierownik;
    }

    public void dodajCzłonka(params CzłonekZespołu[] c)
    {
        foreach (var czlonek in c)
        {
            członkowie.Add(czlonek);
            liczbaCzłonków++;    
        }
    }

    public new string ToString()
    {
        StringBuilder sb = new StringBuilder();
        sb.Append($"Zespół: {nazwa}\n");
        sb.Append($"Kierownik: {kierownik.ToString()}\n");
        foreach (var czlonek in członkowie)
        {
            sb.Append(czlonek.ToString() + "\n");
        }
        return sb.ToString();
    }

    public bool jestCzlonkiem(string pesel)
    {
        foreach (var czlonek in członkowie)
        {
            if (czlonek.Pesel == pesel)
            {
                return true;
            }
        }

        return false;
    }
    public bool jestCzlonkiem(string imie, string nazwisko)
    {
        foreach (var czlonek in członkowie)
        {
            if (czlonek.Imie == imie && czlonek.Nazwisko == nazwisko)
            {
                return true;
            }
        }

        return false;
    }

    public void usunCzlonka(string pesel)
    {
        członkowie.Remove(członkowie.Find(c => c.Pesel == pesel));
        liczbaCzłonków--;
    }
    public void usunCzlonka(string imie, string nazwisko)
    {
        członkowie.Remove(członkowie.Find(c => c.Nazwisko == nazwisko && c.Imie == imie));
        liczbaCzłonków--;
    }

    public void usunWszystkich()
    {
        członkowie.Clear();
        liczbaCzłonków = 0;
    }
    
    public List<CzłonekZespołu> wyszukajCzlonkow(string funkcja)
    {
        List<CzłonekZespołu> result = członkowie.FindAll(c => c.funkcja == funkcja);
        return result;
    }
    public List<CzłonekZespołu> wyszukajCzlonkow(int miesiac)
    {
        List<CzłonekZespołu> result = członkowie.FindAll(c => c.dataZapisu.Month == miesiac);
        return result;
    }
}