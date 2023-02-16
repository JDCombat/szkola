#include <ctime>
#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

ifstream in;
ofstream out;
void zamien(int& a, int& b) {
    int pom = a;
    a = b;
    b = pom;
}

void bubbleSort(int tab[], int n) {
    bool zamiana;
    for (int j = 1; j < n; j++) {
        zamiana = false;
        for (int i = 0; i < n - j; i++) {
            zamien(tab[i], tab[i + 1]);
            zamiana = true;
        }
        if (!zamiana) return;
    }
}
float Profile(int num) {
    float v;
    float* ttab = new float[num];
    clock_t t1;
    clock_t t2;
    for (int i = 0; i < num; i++) {
        t1 = clock();
        
        int tab[100000];
            for (int i = 0; i < 100000; i++) {
                tab[i] = rand() % 100;
        }

            bubbleSort(tab, sizeof(tab));
        t2 = clock();
        ttab[i] = (float)(t2 - t1) / CLOCKS_PER_SEC;
    }
    sort(ttab, ttab + num);
    v = 0.0f;
    for (int i = 1; i < num - 1; i++) {
        v = v + ttab[i];
    }

    v /= (float)(num - 2.0f);

    out.open("wyniki.txt");
    if (out.good()) {
        out << v;
        out.close();
    }

    delete[] ttab;
    return v;
}



int main() {
    cout << Profile(5);
}