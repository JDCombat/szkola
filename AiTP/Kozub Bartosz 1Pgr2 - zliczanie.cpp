#include <iostream>
using namespace std;
int min(int tab[]);
int max(int tab[]);
int sort(int tab[]);
int mini = 0;
int maxi = 0;

int main(){
    int inp;
    cout << "Podaj ilosc liczb" << endl;
    cin >> inp;
    int tab[inp];
    for(int i = 0;i<sizeof(tab);i++){
        tab[i] = rand()%150 - 100;
        cout << tab[i] << " ";
    }
    cout << endl << endl;
    sort(tab);
}

int sort(int tab[]){
    const int temp = maxi-mini+1;
    int t[temp];
}
int min(int tab[]){
    for(int i = 0;i<sizeof(tab);i++){
        if (tab[i]<mini){
            mini = tab[i];
        }
    }
}

int max(int tab[]){
    for (int i = 0; i<sizeof(tab);i++){
        if(tab[i]>maxi){
            maxi = tab[i];
        }
    }
}