#include "../headers/matrix.h"
#include "../headers/function.h"
#include <iostream>
using namespace std;
matrix add(matrix &A, matrix &B){
    if(A.get_m() != B.get_m() || A.get_n() != B.get_n()){
        throw std::invalid_argument("Macierze muszą być tej samej wielkości");
    }
    matrix suma(A.get_m(), A.get_n(), "Wynik dodawania macierz: " + A.get_name() + " i " + B.get_name());
    for (int i = 0; i < A.get_m(); i++){
        for (int j = 0; j < A.get_n(); j++){
            suma.set(i,j,A.get(i,j)+B.get(i,j));
        }
    }
    return suma;
}
matrix multiplyScalar(matrix &A, double skalar){
    matrix wynik(A.get_m(), A.get_n(), "Wynik mnożenia przez skalar macierzy " + A.get_name());
    for (int i = 0; i<A.get_m(); i++){
        for (int j = 0; j<A.get_n(); j++){
            wynik.set(i,j,A.get(i,j)*skalar);
        }
    }
    return wynik;
}
matrix multiply(matrix &A, matrix &B){
    if (A.get_n() != B.get_m()){
        throw std::invalid_argument("Macierze mają być rozmiarów MxK i KxN");
    }
    matrix wynik(A.get_m(),B.get_n(),"Wynik mnożenia macierz: " + A.get_name() + " i " + B.get_name());
    double sum;
    for (int i = 0; i<A.get_m(); i++){
        for (int j = 0; j<B.get_n(); j++){
            for (int k = 0; k<B.get_m();k++){
                sum += A.get(i,k)*B.get(k,j);
                wynik.set(i,j,sum);
            }
            sum = 0;
        }
    }
    return wynik;
}
matrix operator+ (matrix &A, matrix &B){
    if(A.m != B.m || A.n != B.n){
        throw std::invalid_argument("Macierze muszą być tej samej wielkości");
    }
    matrix suma(A.m, A.n, "Wynik dodawania macierz: " + A.name + " i " + B.name);
    for (int i = 0; i < A.m; i++){
        for (int j = 0; j < A.n; j++){
            //suma.set(i,j,A.get(i,j)+B.get(i,j));
            suma.set(i,j,A.a[i][j]+B.a[i][j]);
        }
    }
    return suma;
}

matrix operator* (matrix a, const double scalar){
    matrix wynik(a.m, a.n, "Wynik mnożenia macierzy: " + a.name + " przez skalar " + to_string((int)scalar));
    for (int i = 0; i<a.m; i++){
        for (int j = 0; j<a.n; j++){
            wynik.set(i,j,a[i][j]*scalar);
        }
    }
    return wynik;
}

matrix operator* (matrix &A, matrix &B){
    if (A.n != B.m){
        throw std::invalid_argument("Macierze mają być rozmiarów MxK i KxN");
    }
    matrix wynik(A.m,B.n,"Wynik mnożenia macierzy: " + A.name + " i " + B.name);
    double sum;
    for (int i = 0; i<A.m; i++){
        for (int j = 0; j<B.n; j++){
            for (int k = 0; k<B.m;k++){
                sum += A.a[i][k]*B.a[k][j];
                wynik.set(i,j,sum);
            }
            sum = 0;
        }
    }
    return wynik;
}
istream& operator>> (istream& s, matrix& a){
    for (int i = 0;i<a.get_m();i++){
        for (int j = 0; j<a.get_n();j++){
            s >> a[i][j];
        }
    }
    return s;
}
ostream& operator<< (ostream& s, matrix a){
    s << a.name << endl;
    for (int i = 0;i<a.m;i++){
        for (int j = 0; j<a.n;j++){
            s << a.get(i,j) << "\t";
        }
        s << "\n";
    }
    s << "\n";
    return s;
}