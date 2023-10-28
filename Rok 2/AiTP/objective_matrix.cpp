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
        string get_name();
        matrix transpose();
        ~matrix();
        matrix minor(int j);
        static double laplace(matrix tab)
        {
            if(tab.get_m() != tab.get_n()){
                throw std::invalid_argument("Macierz musi być o rzomiarach MxM");
            }
            if(tab.get_m()==1)
                return tab.get(0,0);
            double wyznacznik = 0;
            for(int j=0; j<tab.get_m(); j++)
                wyznacznik += pow(-1, j) * tab.get(0,j) * matrix::laplace(tab.minor(j));
            return wyznacznik;
        }
        matrix operator+ (const matrix &B);
        matrix operator* (const double scalar);
        matrix operator* (const matrix &B);
        matrix operator= (const matrix &B);
};
matrix add(matrix &A, matrix &B);
matrix multiplyScalar(matrix &A, double skalar);
matrix multiply(matrix &A, matrix &B);

int main(){
    int a,b;
    cout << "Podaj wielkość macierz" << endl;
    cin >> a;
    b=a;
    matrix A(a,b,"Pierwsza macierz");
    A.show();
    matrix B(a,b,"Druga macierz");
    B.show();
    
    // add(A,B).show()
    (A+B).show();

    int skalar;
    cout << "\n \nPodaj skalar\n";
    cin >> skalar;
    // multiplyScalar(B,skalar).show()
    (B*skalar).show();

    cout << "Podaj wymiary pierwszej macierzy do mnożenia\n \n";
    int e,f;
    cin >> e >> f;
    matrix mA(e,f,"Pierwsza macierz do mnożenia");
    cout << "" << endl;
    mA.show();

    cout << "Podaj wymiary drugiej macierzy do mnożenia\n \n";

    int g,h;
    cin >> g >> h;
    matrix mB(g,h,"Druga macierz do mnożenia");
    mB.show();

    // multiply(mA,mB).show()
    (mA*mB).show();
    mB.transpose().show();

    cout << "Wyznacznik pierwszej macierzy\n";

    cout << matrix::laplace(A) << endl << endl;

    // matrix copy(B).show()
    matrix copy;
    (copy = B).show();

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
    cout << name << endl;
    for (int i = 0; i < m; i++){
        cout << "\n";
        for (int j = 0; j < n; j++){
            cout << a[i][j] << " " ;
        }
    }
    cout << endl << endl;
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
    this->name = "Kopia " + m.name;
    create(m.m, m.n);

    for (int i = 0;i<m.m;i++){
        for (int j = 0; j<m.n;j++){
            a[i][j] = m.a[i][j];
        }
    }
}
matrix matrix::operator= (const matrix &B){
    matrix m_copy(B);
    return m_copy;
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

string matrix::get_name(){
    return this->name;
}

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
matrix matrix::operator+ (const matrix &B){
    if(m != B.m || n != B.n){
        throw std::invalid_argument("Macierze muszą być tej samej wielkości");
    }
    matrix suma(m, n, "Wynik dodawania macierz: " + name + " i " + B.name);
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            //suma.set(i,j,A.get(i,j)+B.get(i,j));
            suma.set(i,j,a[i][j]+B.a[i][j]);
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
matrix matrix::operator* (double skalar){
    matrix wynik(m, n, "Wynik mnożenia macierzy: " + name + " przez skalar " + to_string((int)skalar));
    for (int i = 0; i<m; i++){
        for (int j = 0; j<n; j++){
            wynik.set(i,j,a[i][j]*skalar);
        }
    }
    return wynik;
}
matrix multiply(matrix &A, matrix &B){
    if (A.get_n() != B.get_m()){
        throw std::invalid_argument("Macierze mają być rozmiarów MxK i KxN");
    }
        matrix wynik(A.get_m(),B.get_n(),"Wynik mnożenia macierz " + A.get_name() + " i " + B.get_name());
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
matrix matrix::operator* (const matrix &B){
    if (n != B.m){
        throw std::invalid_argument("Macierze mają być rozmiarów MxK i KxN");
    }
        matrix wynik(m,B.n,"Wynik mnożenia macierzy " + name + " i " + B.name);
        double sum;
        for (int i = 0; i<m; i++){
            for (int j = 0; j<B.n; j++){
                for (int k = 0; k<B.m;k++){
                    sum += a[i][k]*B.a[k][j];
                    wynik.set(i,j,sum);
                }
                sum = 0;
            }
        }
        return wynik;
}

matrix matrix::transpose(){
    matrix A(n,m,"Transponowana macierz: " + name);
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
