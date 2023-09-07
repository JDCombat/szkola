#include <iostream>
using namespace std;
void sortowanie(int liczby[], int n);
int main(){

int tab[10];

for (int i = 0;i<10;i++){
    tab[i] = rand()%100;
    cout << tab[i];
}
sortowanie(tab, 10);

for (int i = 0;i<10;i++){
    cout << tab[i];
}
}




void sortowanie(int liczby[], int n){
    int max = liczby[0];
    int min = liczby[0];

    int r;
    for (int i=1;i<n;i++){
        if(min>liczby[i]) {min = liczby[i];}
        if(max<liczby[i]) {max = liczby[i];}
    }
    r = max - min + 1;
    int kubelki[r];
    for (int i = 0;i<r;i++){
        kubelki[i] = 0;
    }

    for (int i = 0; i<r;i++){
        kubelki[liczby[i]-min]++;
    }
    int x = 0;
    for (int i = 0;i<r;i++){
        for (int j= 0;j<kubelki[i];j++){
            liczby[x] = i+min;
        }
    }
}