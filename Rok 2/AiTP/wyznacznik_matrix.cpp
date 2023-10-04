#include <iostream>
#include <cmath>
using namespace std;

// int minor(int* matrix[], int n){
//     int result;
    
//     for (int i = 0;i<n;i++){
//         if(i == ){

//         }
//         result = pow((-1),1+j)*matrix[2][i]*minor(matrix, n);
//     }
//     return result;
// }

int laplace(int* matrix[], int n){
    if (n==1){
        return matrix[0][0];
    }
    else{
    int result = 0;
    int i = 0;
    for (int j = 0; j<n; j++){
        result+=pow(-1,i+j)*matrix[i][j]*laplace(matrix,n-1);
    }
    return result;
    }
}

int main(){
    int n;
    cout << "Wprowadź rozmiar macierzy" << endl;
    cin >> n;
    int **tab1;
    tab1 = new int* [n];
    for (int i = 0; i<n;i++){
            tab1[i] = new int [n];
        for(int j = 0; j<n; j++){
            tab1[i][j] = rand()%10;
        }
    }

    cout << "Wygenerowana macierz" << endl;
        for (int i = 0; i < n; i++){
        cout << "\n";
        for (int j = 0; j < n; j++){
            cout << tab1[i][j] << " " ;
        }
    }
    cout << "\n" << "\n";
    cout <<"Wynik to " << laplace(tab1, n);

}