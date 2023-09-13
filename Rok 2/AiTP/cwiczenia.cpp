#include <iostream>
using namespace std;

double calcRatio(int m, int n){
    if(n == 0) return 1000000;
    return (double)m/n;
}

int main(){
    int n, m;
    unsigned long long sum;
    cout << "Podaj wymiar tablicy (MxN)" << endl;
    cin >> n >> m;
    int **tab1;
    tab1 = new int* [m];
    for (int i = 0 ;i<m;i++){
        tab1[i] = new int[n];
    }
    for (int i = 0;i<m;i++){
        for (int j = 0;j<n;j++){
            tab1[i][j] = rand()%n;

           if(calcRatio(i, j) <= (double)m/n){
                tab1[i][j] = 0;
            }
            cout << tab1[i][j] << " ";
            sum += tab1[i][j];
        }
        cout << endl;
    }

    cout << "Suma wynosi " << sum << endl;
}