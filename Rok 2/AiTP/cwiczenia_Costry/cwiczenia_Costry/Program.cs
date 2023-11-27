using System.Text.RegularExpressions;

namespace Aitp_excercises
{
    internal class Program
    {
        static void cw1()
        {
            Console.WriteLine("Podaj pierwszą liczbę");
            double first;
            first = double.Parse(Console.ReadLine());
            Console.WriteLine("Podaj drugą liczbę");
            float second;
            second = float.Parse(Console.ReadLine());
            Console.WriteLine(Math.Round(first + second, 2));
            Console.WriteLine(Math.Round(first - second, 2));
            Console.WriteLine(Math.Round(first * second, 2));
            Console.WriteLine(Math.Round(first / second, 2));
        }

        static void cw1star()
        {
            int sum = 0;
            int count = 0;
            int avg = 0;
            int[] tab = new int[10];
            for (int i = 0; i < 10; i++)
            {
                Console.WriteLine("Podaj " + (i + 1)  + "liczbę");
                tab[i] = int.Parse(Console.ReadLine());
                if (tab[i] % 3 == 0 || tab[i] % 5 == 0)
                {
                    sum += tab[i];
                    count++;
                }
            }
            avg = sum / count;
            Console.WriteLine("Suma " + sum);
            Console.WriteLine("Średnia " + avg);
        }

        static bool cw2()
        {
            uint number;
            int digit = 3;
            number = uint.Parse(Console.ReadLine());
            do
            {
                if (number % 3 == 0) return true;
                number /= 10;
            } while (number > 0);

            return false;
        }

        static bool cw2star()
        {
            uint number = 0;
            number = uint.Parse(Console.ReadLine());
            return number.ToString().Contains("3");
        }

        static void cw3()
        {
            string input;
            input = Console.ReadLine();
            string[] s = Regex.Split(input, "([a-zA-Z0-9]+)");
            Console.WriteLine(s[3] + s[2] + s[1]);
        }
        public static void Main(String[] args)
        {
            // cw1();
            // cw1star();
            // Console.WriteLine(cw2() == true ? "Yesh" : "no");
            // Console.WriteLine(cw2star() == true ? "Yesh" : "no");
            cw3();
        }
    }
}

