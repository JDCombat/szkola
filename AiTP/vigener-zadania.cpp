#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
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
        "klmnopqrstuvwxyzabcdefghij",
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
int powt;
string zakoduj(string txt, string klucz) {
    string zwrot;
    int x, y;
    int size = klucz.size();
    while (klucz.size() < txt.size())klucz += klucz;
    powt = floor(klucz.size() / size);
    cout << powt;
    for(int i = 0; i < txt.size(); i++){
        x = 0;
        while (t[x][0] != klucz[i]){
            x++;
        }
        y = 0;
        if(txt[i] == ' ') zwrot += ' ';
        else if(txt[i] == ',') zwrot += ',';
        else if(txt[i] == '.') zwrot += '.';
        else {
            while (txt[i] != t[0][y]) {
                y++;
            }
            zwrot += t[x][y];
        }
    }
    return zwrot;
}

string odkoduj(string txt, int dlugosc, string klucz) {
    string zwrot = "";
    int x,y;
    while (klucz.size() < dlugosc) klucz += klucz;
    for (int i = 0; i < dlugosc; i++){
        x = 0;
        while(t[x][0] != klucz[i]) x++;
        y = 0;
        while(t[x][y] != txt[i]) y++;
        zwrot += t[0][y];
    }
    return zwrot;
}
void zadanie1(){
    ifstream in;
    in.open("dokad.txt");
    string wyraz;
    getline(in, wyraz);
    in.close();
    string tekst = zakoduj(wyraz, "LUBIMYCZYTAC");
    ofstream szyfr;
    szyfr.open("odpowiedz.txt");
    szyfr << powt << " powtorzenia |";
    szyfr << tekst;
    tekst = odkoduj(wyraz,wyraz.size(), "LUBIMYCZYTAC");
    szyfr << endl << endl << tekst;
}

void zadanie2(){
    ifstream in;
    in.open("szyfr.txt");
    string wyraz;
    getline(in, wyraz);
    cout << wyraz << endl << endl;
    string klucz;
    getline(in, klucz);
    in.close();
    string tekst = odkoduj(wyraz,wyraz.size(), klucz);
    ofstream odszyfr;
    odszyfr.open("odszyfrowane.txt");
    cout << tekst;
    odszyfr << tekst;
}

int main(){
    for(int i = 0;i<t->size();i++){
        for(int j = 0;j<t[i].size();j++) {
            t[i][j] = toupper(t[i][j]);

        }
    }
    zadanie1();

}