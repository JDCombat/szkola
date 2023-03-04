#include <iostream>
#include <ctime>
#include <algorithm>
#include <fstream>
#include <chrono>

using namespace std;


void quickSort(int l, int p, int tab[]){
    int i=l, j=p;
    int pivot=tab[(l+p)/2];
    do{
        while(tab[i]<pivot) i++;
        while(tab[j]>pivot) j--;
        if(i<=j){
            int tmp = tab[i];
            tab[i] = tab[j];
            tab[j] = tmp;
            i++;j--;
        }
    }while(i<=j);
    if(l<j) quickSort(l,j,tab);
    if(i<p) quickSort(i,p,tab);
}

void zamien(int &a, int &b){
    int pom = a;
    a = b;
    b = pom;
}

void bubbleSort(int tab[],int n){
    bool zamiana;
    for(int j=1;j<n;j++){
        zamiana=false;
        for(int i=0;i<n-j;i++){
            zamien(tab[i],tab[i+1]);
            zamiana=true;
        }
        if (!zamiana) return;
    }
}

float Profile1(int num){
    double* ttab = new double[num];
    int* tab = new int[num];
    int* t = new int[num];
    for(int i = 0; i < num; i++){
        for(int j=0;j<100*1;j++) tab[j] = (rand() % 1000) + 1;
        auto t1 = std::chrono::high_resolution_clock::now();
        quickSort(0, num - 1, tab);
        auto t2 = std::chrono::high_resolution_clock::now();
        ttab[i] = (std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1)).count();;
    }
    std::sort(ttab, ttab + num);
    return (ttab[1] + ttab[2] + ttab[3] + ttab[4] + ttab[5] + ttab[6] + ttab[7] + ttab[8])/8;
}

float Profile2(int num){
    double* ttab = new double[num];
    int* tab = new int[num];
    for(int i = 0; i < num; i++){
        for(int j=0;j<num;j++) tab[j] = (rand() % 1000) + 1;
        auto t1 = std::chrono::high_resolution_clock::now();
        bubbleSort(tab, num);
        auto t2 = std::chrono::high_resolution_clock::now();
        ttab[i] = (std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1)).count();
    }
    std::sort(ttab, ttab + num);
    return (ttab[1] + ttab[2] + ttab[3] + ttab[4] + ttab[5] + ttab[6] + ttab[7] + ttab[8])/8;
}
int main() {
    srand(time(NULL));
    ofstream out;
    out.open("wynik.txt");
    for (int i = 1; i < 11; i++) {
        out << Profile1(i*1000) << endl;
    }
    out << endl;
    for (int i = 1; i < 11; i++) {
        out << Profile2(i*100) << endl;
    }
    out.close();
    return 0;
}
