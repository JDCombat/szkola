using System.Text;

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
}