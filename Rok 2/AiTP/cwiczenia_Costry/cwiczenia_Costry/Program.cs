using System.Text.RegularExpressions;

namespace cwiczenia_Costry
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

        static int sumDigits(int a)
        {
            int sum = 0;
            string aString = a.ToString();
            for (int i = 0; i < aString.Length; i++)
            {
                sum += int.Parse(aString[i].ToString());
            }

            return sum;
        }
        static int cw4()
        {
            int a = 0;
            a = int.Parse(Console.ReadLine());
            do
            {
                a = sumDigits(a);
            } while (a >= 10);

            return a;
        }

        static string cw5(string text)
        {
            int counter = 0;
            char currentCharacter = text[0];
            string txt_return = "";
            for (int i = 0; i < text.Length; i++)
            {
                if (text[i] == currentCharacter)
                {
                    counter++;
                }
                else
                {
                    txt_return += currentCharacter;
                    if (counter > 1)
                    {
                        txt_return += counter;
                    }

                    currentCharacter = text[i];
                    counter = 1;
                }
                
            }
            txt_return += currentCharacter;
            if (counter > 1)
            {
                txt_return += counter;
            }
            return txt_return;
        }
        static double[] cw6()
        {
            Random rnd = new Random();
            double[] tab = new double[10];
            for (int i = 0; i < 10; i++)
            {
                tab[i] = rnd.Next(10);
                Console.Write(tab[i] + " ");
            }
            Console.WriteLine();
            for (int i = 0; i < tab.Length - 1; i++)
            {
                for (int j = 0; j < tab.Length - i - 1; j++)
                {
                    if (tab[j] > tab[j + 1])
                    {
                        (tab[j], tab[j + 1]) = (tab[j + 1], tab[j]);
                    }
                }
            }
            return tab;
        }

        static void cw7(int size)
        {
            int[][] pascal = new int[size][];
            for (int i = 0; i < size; i++)
            {
                pascal[i] = new int[i + 1];
            }

            for (int i = 0; i < pascal.Length; i++)
            {
                for (int j = 0; j < i; j++)
                {
                    if (j == 0 || i == j)
                    {
                        pascal[i][j] = 1;
                    }
                    else
                    {
                        pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
                    }
                }
            }

            foreach (var tab in pascal)
            {
                foreach (var item in tab)
                {
                    Console.Write(item + "\t");
                }
                Console.WriteLine();
            }
        }
        static uint nwd(uint a, uint b)
        {
            return (b == 0 ? a : nwd(b, a % b));
        }
        static uint cw8()
        {
            uint a, b;
            a = uint.Parse(Console.ReadLine());
            b = uint.Parse(Console.ReadLine());
            return nwd(a, b);
        }

        static double cw8star(double n, double k)
        {
            if (k == 0 || k == n)
            {
                return 1;
            }
            else if (0 < k && k < n)
            {
                return cw8star(n - 1, k - 1) + cw8star(n - 1, k);
            }
            else
            {
                return 0;
            }
        }
        static int cw9()
        {
            DateTime today = DateTime.Today;
            DateTime end = new DateTime(2023, 12, 31, 23, 59, 59);
            TimeSpan days = end - today;
            return days.Days;
        }

        static void Figura()
        {
            Console.WriteLine("Podaj długość boku");
            int size = int.Parse(Console.ReadLine() ?? throw new InvalidOperationException());
            char[,] tab = new char[size, size];
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    tab[i, j] = ' ';
                    tab[0, j] = '*';
                    tab[size - 1, j] = '*';
                }
                tab[i, 0] = '*';
                tab[i, size - 1] = '*';
                tab[i, i] = '*';
                tab[i, size - i - 1] = '*';
                
                for (int j = 0; j < size; j++)
                {
                    Console.Write(tab[i, j] + " ");
                }
                Console.WriteLine();
            }


        }
        static void Kalkulator()
        {
            Console.WriteLine("Podaj pierwszą liczbę");
            double a = double.Parse(Console.ReadLine());
            Console.WriteLine("Podaj znak");
            char znak = Console.ReadLine()[0];
            double b = double.Parse(Console.ReadLine());
            string result = "";
            switch (znak)
            {
                case '+': result = $"{a:N}\n{znak}\n{b:N}\n=\n{a + b:N}"; break;
                case '-': result = $"{a:N}\n{znak}\n{b:N}\n=\n{a - b:N}"; break;
                case '*': result = $"{a:N}\n{znak}\n{b:N}\n=\n{a * b:N}"; break;
                case '/': result = $"{a:N}\n{znak}\n{b:N}\n=\n{a / b:N}"; break;
            }

            Console.WriteLine(result);
        }
        static void Tablica()
        {
            Random rnd = new Random();
            int n;
            int even = 0, odd = 0;
            n = int.Parse(Console.ReadLine());
            int[] tab = new int[n];
            Console.WriteLine("Tablica");
            for (int i = 0; i < n; i++)
            {
                tab[i] = rnd.Next(-100, 100);
                Console.Write(tab[i] + " ");
                if (tab[i] % 2 == 0) even++;
                else odd++;
            }
            Console.WriteLine("\nParzyste " + even + "\n" + "Nieparzyste " + odd);
        }

        static void TablicaZnaków()
        {
            Console.WriteLine("Podaj ciąg maksymalnie 30 znaków");
            string answer = Console.ReadLine();
            string toReturn = "";
            string alphabet = "abcdefghijklmnoprstuwyzżźABCDEFGHIJKLMNOPRSTUWYZŻŹ";
            if (answer.Length > 30)
            {
                Console.WriteLine("Nie możesz podać więcej niż 30 znaków");
            }
            else
            {
                for (int i = 0; i < answer.Length; i++)
                {
                    if (alphabet.Contains(answer[i]))
                    {
                        toReturn += answer[i];
                    }
                }
            }
            Console.WriteLine(toReturn);
        }
        public static void Main(String[] args)
        {
            // cw1();
            // cw1star();
            // Console.WriteLine(cw2() == true ? "Yesh" : "no");
            // Console.WriteLine(cw2star() == true ? "Yesh" : "no");
            // cw3();
            // Console.WriteLine(cw5("kkkktttrrrrrrrrr"));
            // Console.WriteLine(cw4());
            // foreach(var item in cw6())
            // {
            //     Console.Write(item + " ");
            // }
            // cw7(7);
            // Console.WriteLine(cw8());
            // Console.WriteLine(cw8star(10,5));
            // Console.WriteLine(cw9());
            Figura();
            // Tablica();
            // TablicaZnaków();
            // Kalkulator();
        }
    }
}

