#include <iostream>
#include <string>
#include <fstream>
using namespace std;

string t[26] = {
        "abcdefghijklmnopqrstuvwxyz",
        "bcdefghijklmnopqrstuvwxyza",
        "cdefghijklmnopqrstuvwxyzab",
        "defghijklmnopqrstuvwxyzabc",
        "efghijklmnopqrstuvwxyzabcd",
        "fghijklmnopqrstuvwxyzabcde",
        "ghijklmnopqrstuvwxyzabcdef",
        "hijklmnopqrstuvwxyzabcdefg",
        "ijklmnoprstuvwxyzabcdefgh",
        "jklmnopqrstuvwxyzabcdefghi",
        "klmnopqrstuvwxyzabcdefghij ",
        "lmnopqrstuvwxyzabcdefghijk",
        "mnopqrstuvwxyzabcdefghijkl",
        "nopqrstuvwxyzabcdefghijklm",
        "opqrstuvwxyzabcdefghijklmn",
        "pqrstuvwxyzabcdefghijklmno",
        "qrstuvwxyzabcdefghijklmnop",
        "rstuvwxyzabcdefghijklmnopq",
        "stuvwxyzabcdefghijklmnopqr",
        "tuvwxyzabcdefghijklmnopqrs ",
        "uvwxyzabcdefghijklmnopqrst",
        "vwxyzabcdefghijklmnopqrstu",
        "wxyzabcdefghijklmnopqrstuv",
        "xyzabcdefghijklmnopqrstuvw",
        "yzabcdefghijklmnopqrstuvwx",
        "zabcdefghijklmnopqrstuvwxy"
};

string zakoduj(string txt, string klucz);
string odkoduj(string txt, int dlugosc, string klucz);
int main() {
    ifstream in;
    in.open("text.txt");
    string wyraz;
    getline(in, wyraz);
    in.close();
    string klucz = "make";
    string tekst = zakoduj(wyraz, klucz);
    ofstream szyfr, czysty;
    szyfr.open("szyfrogram.txt");
    cout << tekst;
    szyfr << tekst;
    szyfr.close();
    tekst = odkoduj(tekst, 6, "ciupal");
    czysty.open("odszyfrowane.txt");
    cout << tekst;
    czysty << tekst;
}

string zakoduj(string txt, string klucz) {
    string zwrot = "";
    int x, y;
    while (klucz.size() < txt.size())klucz += klucz;
    for(int i = 0; i < txt.size(); i++){
        x = 0;
        while (t[x][0] != klucz[i]){
            x++;
        }
        y = 0;
        while (txt[i] != t[0][y]){
            y++;
        }
        zwrot += t[x][y];
    }
    return zwrot;
}
string odkoduj(string txt, int dlugosc, string klucz) {
    string zwrot = "";
    int x,y;
    while (klucz.size() < dlugosc) klucz += klucz;
    for (int i = 0; i < txt.size(); i++){
        x = 0;
        while(t[x][0] != klucz[i]) x++;
        y = 0;
        while(t[x][y] != txt[i]) y++;
        zwrot += t[0][y];
    }
    return zwrot;
}
//
// Created by Kozub Bartosz on 13.04.2023.
//
