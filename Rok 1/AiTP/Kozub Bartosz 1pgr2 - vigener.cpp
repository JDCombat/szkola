#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <iomanip>

using namespace std;

ifstream f, szyfr;
ofstream out;


int wydluzKlucz(string &klucz, const string& tekst) {
    int itr = 1;
    string initialKey = klucz;
    while (klucz.length() <= tekst.length()) {
        klucz += initialKey;
        itr++;
    }
    return itr;
}


void zaszyfruj(string klucz, string tekst, string t[]) {
    int firstIndex, secondIndex, count = 0;
    out << "Zaszyfrowana wiadomość: ";

    for (int i = 0; i < tekst.length(); i++){
        if (tekst[i] == '.') {
            out << '.';
            count++;
            continue;
        }
        if (tekst[i] == ',') {
            out << ',';
            count++;
            continue;
        }
        if (tekst[i] == ' ')
        {
            out << ' ';
            count++;
            continue;
        }

        for (int j = 0; j < 26; j++){
            if(t[0][j] == tekst[i]){
                firstIndex = j;
            }
            if (t[j][0] == klucz[i-count]){
                secondIndex = j;
            }
        }

        out << t[firstIndex][secondIndex];
    }
    out << '\n';
}


void odszyfruj(string tekst, string klucz, string t[]) {
    int index, count = 0;
    out << "Odszyfrowana wiadomość: ";
    for (int i = 0; i < tekst.length(); i++){
        if (tekst[i] == '.') {
            out << '.';
            count++;
            continue;
        }
        if (tekst[i] == ',') {
            out << ',';
            count++;
            continue;
        }
        if (tekst[i] == ' ') {
            out << ' ';
            count++;
            continue;
        }

        for (int j = 0; j < 26; j++){
            if(t[0][j] == klucz[i-count]){
                index = j;
                for (int k = 0; k < 26; k++) {
                    if (t[k][index] == tekst[i]) {
                        out << t[k][0];
                    }
                }
            }
        }
    }
    out << '\n';
}



void znajdzKlucz(string t[], string tekst) {
    int tab[26], suma = 0;
    out << "Liczba powtórzeń poszczególnych liter: \n";
    for (int i = 0; i < 26; i++){
        tab[i] = count(tekst.begin(), tekst.end(), t[0][i]);
        out << "\t" << t[0][i] << ": " << tab[i] << '\n';
        suma += tab[i];
    }

    double fragment1 = 0;
    for (int i : tab) {
        fragment1 += i*(i-1);
    }

    double fragment2 = fragment1 / (suma*(suma-1));
    double wynik = 0.0285 / (fragment2 - 0.0385);

    out << "Szacowana długość klucza: " << setprecision(4) << wynik << '\n';
    szyfr.close();
}

int main(){
    string t[26];
    f.open("dokad.txt");
    szyfr.open("szyfr.txt");
    out.open("wyniki.txt");

    string tekst, klucz = "LUBIMYCZYTAC";
    getline(f, tekst, '\n');

    for (int i = 0; i < 26; i++){
        for (int j = 0; j < 26; j++) {
            int znak = (i+j)%26+65;
            t[i] += (char)znak;
        }
    }

    string key2, passphrase2;

    getline(szyfr, passphrase2, '\n'); 
    getline(szyfr, key2, '\n'); 
    string key3 = key2;

    out << "Liczba powtórzeń klucza: " << wydluzKlucz(klucz, tekst) << '\n';

    wydluzKlucz(key2, passphrase2);
    zaszyfruj(klucz, tekst, t);
    odszyfruj(passphrase2, key2, t);
    znajdzKlucz(t, passphrase2);

    out << "Rzeczywista długość klucza: " << key3.length();

    out.close();
    szyfr.close();

    return 0;
}