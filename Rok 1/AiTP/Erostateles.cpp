#include <iostream>
#include <cmath>

using namespace std;


bool isPrime(int liczba) {
    if (liczba > 2)
        if (liczba % 2 == 0)
            return false;
    for (int i = 3; pow(i, 2) < liczba; i += 2)
        if (liczba % i == 0)
            return false;
    return true;
}

int factorio(int liczba) {
    int start = liczba / 2;
    int wynik[liczba];
    for (int i = 0; i < liczba; i++) wynik[i] = 0;
    int miejsce = 0;
    while (liczba != 1)
        for (int i = 2; i <= start; i++)
            if (liczba % i == 0) {
                liczba /= i;
                wynik[miejsce] = i;
                miejsce++;
            }
    int x = 0;
    while (wynik[x] != 0) x++;
    for (int i = 0; i < x; i++) cout << ' ' << wynik[i] << ',';
    return 1;
}

bool isPerfect(int liczba) {
    int test = 0;
    int tab[liczba / 2];
    for (int i = 1; i <= liczba / 2; i++)
        tab[i] = i;
    for (int i = 1; i <= liczba / 2; i++)
        if (liczba % tab[i] == 0)
            test += tab[i];
    if (test == liczba)
        return true;
    else
        return false;
}

int nwd(int a, int b) {
    while (a != b)
        if (a > b)
            a -= b;
        else
            b -= a;
    return a;
}

bool fermata(int liczba, int k) {
    srand(time(NULL));
    long long a = (rand() % (liczba - 1)) + 1;
    long long potega;
    if (nwd(a, liczba) == 1) {
        potega = a;
        for (int i = 0; i < liczba - 2; i++) potega = (potega * a) % liczba;
        if (potega == 1)
            if (k == 1)
                return true;
            else
                fermata(liczba, k - 1);
    }
    return false;
}

int erotestenes(int liczba) {
    int tab[liczba - 2];
    for (int i = 2; i <= liczba; i++) tab[i - 2] = i;
    int a = 0;
    for(int a = 0; a < liczba - 2; a++)
        for(int i = 0; i < a; i++)
            if (tab[i] != 0 && tab[a] != 0)
                if (tab[a] % tab[i] == 0)
                    tab[a] = 0;
    for(int i = 0; i < liczba - 2; i++)
        if (tab[i] != 0)
            cout << tab[i] << ' ';
    cout << endl;
    return 0;
}

int main() {
    erotestenes(40);
    return 0;
}

