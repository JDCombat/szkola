namespace Firma
{
    public enum Plcie
    {
        K,
        M
    }
    internal class Program
    {
        public static void Main(String[] args)
        {
            CzłonekZespołu os1 = new CzłonekZespołu("Beata", "Nowak", "1992-10-22", "92102201346", Plcie.K,  "01.01.2020","projektant");
            KierownikZespołu os2 = new KierownikZespołu("Jan", "Jankowski", "1993-03-15", "92031507772", Plcie.M, 5);
            CzłonekZespołu os3 = new CzłonekZespołu("Witold", "Adamski", "22.10.1992", "92102266738", Plcie.M,
                "01.01.2022", "sekretarz");
            
            Console.WriteLine(os1.ToString());
            Console.WriteLine(os2.ToString());
            Console.WriteLine(os3.ToString());
            Console.WriteLine();
            Console.WriteLine();
            Zespół it = new Zespół("Grupa it", os2);
            it.dodajCzłonka(os1, os3);
            Console.WriteLine(it.ToString());
        }
    }
}