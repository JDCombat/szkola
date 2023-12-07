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
            Osoba os1 = new Osoba("Beata", "Nowak", "1992-10-22", "92102201346", Plcie.K);
            Osoba os2 = new Osoba("Jan", "Jankowski", "1993-03-15", "92031507772", Plcie.M);
            
            Console.WriteLine(os1);
            Console.WriteLine(os2);
            Console.WriteLine(os1.checkPESEL());
        }
    }
}