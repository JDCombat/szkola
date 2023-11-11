#include "../headers/matrix.h"
using namespace std;
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
            cout << a[i][j] << "\t" ;
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

string matrix::get_name(){
    return this->name;
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
double* matrix::operator[] (int i){
    return this->a[i];
}