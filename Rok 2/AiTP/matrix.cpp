#include <iostream>
using namespace std;
int m, n, o, p;

int** matadd(int* matrix[], int* matrix2[]){
    int **wynik;
    wynik = new int* [m];
    for (int i = 0; i<m; i++){
            wynik[i] = new int [n];
        for (int j = 0; j<n; j++){
            wynik[i][j] = matrix[i][j] + matrix2[i][j];
        
        }
}
    return wynik;
}

int** matskalar(int* matrix[], int skalar){
    int **wynik;
    wynik = new int* [m];
    for (int i = 0; i<m; i++){
        wynik[i] = new int [n];
        for (int j = 0; j<n; j++){
            wynik[i][j] = matrix[i][j] * skalar;
        }
    }
    return wynik;
}

int** matmultip(int* matrix[], int* matrix2[]){
    if (n != o){
        return 0;
    }
    else{
        int **wynik;
        wynik = new int* [m];
        for (int i = 0; i<m; i++){
            wynik[i] = new int [o];
            for (int j = 0; j<n; j++){
            }
        }
    }
}

int main(){
    cout << "Wpisz rozmiar pierwszej macierzy macierzy(MxN)" << endl;
    cin >> m >> n;
    cout << "Wpisz rozmiar drugiej macierzy" << endl;
    cin >> o >> p;

    int **tab1;
    tab1 = new int* [m];
    for (int i = 0; i<m;i++){
            tab1[i] = new int [n];
        for(int j = 0; j<n; j++){
            tab1[i][j] = rand()%10;
        }
    }
    int **tab2;
    tab2 = new int* [m];
    for (int i = 0; i<m;i++){
            tab2[i] = new int [n];
        for(int j = 0; j<n; j++){
            tab2[i][j] = rand()%10;
        }
        
    }
    int **res = matskalar(tab1, 9);
    for (int i = 0; i < m; i++){
        cout << "\n";
        for (int j = 0; j < n; j++){
            cout << res[i][j] << " " ;
        }
    }

    return 0;
}