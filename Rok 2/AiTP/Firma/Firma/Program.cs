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
            CzłonekZespołu os1 = new CzłonekZespołu("Beata", "Nowak", "12.01.2007", "92102201346", Plcie.K,  
                "01.01.2020","projektant");
            KierownikZespołu os2 = new KierownikZespołu("Jan", "Jankowski", "1993-03-15", "92031507772", Plcie.M, 5);
            CzłonekZespołu os3 = new CzłonekZespołu("Witold", "Adamski", "22.10.1992", "92102266738", Plcie.M,
                "01.01.2022", "sekretarz");
            CzłonekZespołu os4 = new CzłonekZespołu("Jan", "Jankowski", "25.12.1984", "92031532652", Plcie.M,
                "01.01.2020", "sekretarz");
            
            Console.WriteLine(os1.ToString());
            Console.WriteLine(os1.Wiek());
            Console.WriteLine(os2.ToString());
            Console.WriteLine(os3.ToString());
            Console.WriteLine();
            Zespół it = new Zespół("Grupa it", os2);
            it.dodajCzłonka(os1, os3, os4);
            Console.WriteLine(it.ToString());
            // Console.WriteLine(it.jestCzlonkiem("92102201346"));
            Console.WriteLine(it.jestCzlonkiem("Witold", "Adamski"));
            foreach (var czlonek in it.wyszukajCzlonkow("sekretarz"))
            {
                Console.WriteLine(czlonek.ToString());
            }
            Console.WriteLine();
            it.usunCzlonka("Jan", "Jankowski");
            Console.WriteLine(it.ToString());

            CzłonekZespołu kopia = (CzłonekZespołu)os4.Clone();
            Console.WriteLine(kopia.ToString());
            
            KierownikZespołu kopia2 = (KierownikZespołu)os2.Clone();
            Console.WriteLine(kopia2.ToString());
            
            Console.WriteLine();
            
            Zespół kopia3 = (Zespół)it.Clone();
            Console.WriteLine(kopia3.ToString());
            
            // it.sortuj();
            // Console.WriteLine(it.ToString());


            it.sortujPoPESEL();
            Console.WriteLine(it.ToString());

            Console.WriteLine(it.jestCzlonkiem(os1));
            
            it.ZapiszBin("it");

            Zespół serkj = (Zespół)it.OdczytajBin("it");
            Console.WriteLine(serkj.ToString());


            Zespół.ZapiszXML("zespol.xml", it);
            Zespół hgdfhdsf = (Zespół)Zespół.OdczytajXML("zespol.xml");
            Console.WriteLine(hgdfhdsf.ToString());
        }
    }
}