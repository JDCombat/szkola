#include <iostream>
using namespace std;

void zamien(int &a, int &b){
    int pom = a;
    a = b;
    b = pom; 
}

void bubblesort(int tab[], int n){
    bool zamiana;
    for(int j=1;j<n;j++){
        zamiana = false;
        for(int i=0; i<n-j;i++)
            if(tab[i]>tab[i+1]){
                zamien(tab[i], tab[i+1]);
                zamiana = true;
            }
            if(!zamiana) return;
    }
}

int main(){
    int n;
    cout << "Podaj liczbe" << endl;
    cin >> n;
    int liczby[n-1];
    for(int i = 0;i<(sizeof(liczby)/4)+1;i++){
    int x = (rand()%n)+1;
    liczby[i] = x;
}

bubblesort(liczby, n);
for (int i = 0; i<(sizeof(liczby)/4)+1;i++){
    cout << liczby[i] << " "
}
}