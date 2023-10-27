#include <iostream>
#include <cmath>
using namespace std;


class matrix{
    protected:
        double **a;
        int m = 0;
        int n = 0;
        string name = " ";
    public:
        matrix();
        void create(int x, int y);
        matrix(int x, int y, string N);
        matrix(const matrix& m);
        void fill();
        void show();
        void set(int i, int j, double r);
        double get(int i, int j);
        int get_m();
        int get_n();
        matrix transpose();
        ~matrix();
        matrix minor(int j);
        static double laplace(matrix tab)
        {
            if(tab.get_m()==1)
                return tab.get(0,0);
            double wyznacznik = 0;
            for(int j=0; j<tab.get_m(); j++)
                wyznacznik += pow(-1, j) * tab.get(0,j) * matrix::laplace(tab.minor(j));
            return wyznacznik;
        }
};
matrix add(matrix &A, matrix &B);
matrix multiplyScalar(matrix &A, double skalar);
matrix multiply(matrix &A, matrix &B);

int main(){
    int a,b;
    cout << "Podaj wielkość macierz" << endl;
    cin >> a;
    b=a;
    matrix A(a,b,"Pierwsza");
    cout << "Pierwsza macierz" << endl;
    A.show();
    matrix B(a,b,"Druga");
    cout << "\nDruga macierz" << endl;
    B.show();
    
    cout << " \n \nWynik dodawania\n";
    add(A,B).show();

    int skalar;
    cout << "\n \nPodaj skalar\n";
    cin >> skalar;
    cout << "\n \nWynik mnożenia drugiej macierzy przez skalar" << endl << endl;
    multiplyScalar(B, skalar).show();

    int e,f;
    cout << "\n \nPodaj wielkość pierwszej macierzy do mnożenia" << endl;
    cin >> e >> f;
    matrix mA(e,f,"Multiply1");
    cout << "Pierwsza macierz" << endl;
    mA.show();

    int g,h;
    cout << "\n \nPodaj wielkość pierwszej macierzy do mnożenia" << endl;
    cin >> g >> h;
    matrix mB(g,h,"Multiply1");
    cout << "Druga macierz" << endl;
    mB.show();

    cout << "\n \nWynik mnożenia macierz";
    multiply(mA,mB).show();
    cout << "\n \n \nTranspozycja pierwszej macieży do mnożenia";
    mB.transpose().show();

    cout << "\n \nWyznacznik pierwszej macierzy\n";

    cout << matrix::laplace(A);
    cout << "\n \nKopia drugiej macierzy";

    matrix copy(B);
    copy.show();

    return 0;
}

matrix::matrix() {
    a = new double *[0];
}
void matrix::create(int x, int y){
    a = new double* [x];
    for (int i = 0; i<x;i++){
        a[i] = new double [y]();
    }
}
void matrix::fill(){
    for (int i = 0; i<m;i++){
        for (int j = 0; j<n;j++){
            a[i][j] = rand()%10;
        }
    }
}
void matrix::show(){
    for (int i = 0; i < m; i++){
        cout << "\n";
        for (int j = 0; j < n; j++){
            cout << a[i][j] << " " ;
        }
    }
}
matrix::matrix(int x, int y, string N){
    this->m = x;
    this->n = y;
    this->name = N;
    create(m, n);
    fill();
}
matrix::matrix(const matrix& m){
    this->m = m.m;
    this->n = m.n;
    this->name = m.name;
    create(m.m, m.n);

    for (int i = 0;i<m.m;i++){
        for (int j = 0; j<m.n;j++){
            a[i][j] = m.a[i][j];
        }
    }
}
void matrix::set(int i, int j, double r){
    this->a[i][j] = r;
}
double matrix::get(int i, int j){
    return this->a[i][j];
}

int matrix::get_m(){
    return this->m;
}

int matrix::get_n(){
    return this->n;
}

matrix add(matrix &A, matrix &B){
    if(A.get_m() != B.get_m() || A.get_n() != B.get_n()){
        throw std::invalid_argument("Macierze muszą być tej samej wielkości");
    }
        matrix suma(A.get_m(), A.get_n(), "Suma");
        for (int i = 0; i < A.get_m(); i++){
            for (int j = 0; j < A.get_n(); j++){
                suma.set(i,j,A.get(i,j)+B.get(i,j));
            }
        }
        return suma;
}
matrix multiplyScalar(matrix &A, double skalar){
    matrix wynik(A.get_m(), A.get_n(), "Wynik mnożenia przez skalar");
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
        matrix wynik(A.get_m(),B.get_n(),"Wynik mnożenia macierzy");
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

matrix matrix::transpose(){
    matrix A(n,m,"A");
    for (int i = 0; i<n;i++){
        for (int j = 0; j<m; j++){
            double set_value = a[j][i];
            A.set(i,j,set_value);
        }
    }
    return A;
}

matrix::~matrix(){
 for (int i=0; i<m; i++)
    {
        delete[] a[i];
    }
    delete[] a;
}
matrix matrix::minor(int j)
{
    matrix minor(m-1,m-1, "nieletni");
    for(int k=0; k<m-1; k++)
        for(int l=0; l<m-1; l++)
        {
            if(l>=j)
               minor.set(k,l, a[k+1][l+1]);
            else{
                minor.set(k,l, a[k+1][l]);
            }
        }
    return minor;
}