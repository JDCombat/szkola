#ifndef _MATRIX_H
#define _MATRIX_H
    #include <iostream>
    #include "stdexcept"
    #include <cmath>
    class matrix{
        protected:
            double **a;
            int m = 0;
            int n = 0;
            std::string name = " ";
        public:
            matrix();
            void create(int x, int y);
            matrix(int x, int y, std::string N);
            matrix(const matrix& m);
            void fill();
            void show();
            void set(int i, int j, double r);
            double get(int i, int j);
            int get_m();
            int get_n();
            std::string get_name();
            matrix transpose();
            ~matrix();
            matrix minor(int j);
            static double laplace(matrix tab)
            {
                if(tab.get_m() != tab.get_n()){
                    throw std::invalid_argument("Macierz musi być o rozmiarach MxM");
                }
                if(tab.get_m()==1)
                    return tab.get(0,0);
                double wyznacznik = 0;
                for(int j=0; j<tab.get_m(); j++)
                    wyznacznik += pow(-1, j) * tab.get(0,j) * matrix::laplace(tab.minor(j));
                return wyznacznik;
            }
            friend matrix operator+ (matrix &A, matrix &B);
            friend matrix operator* (matrix a, const double scalar);
            friend matrix operator* (matrix &A, matrix &B);
            matrix& operator= (const matrix &B){
                this->m = B.m;
                this->n = B.n;
                this->name = B.name;
                this->a = new double*[this->m];
                for (int i = 0;i<m;i++){
                    this->a[i] = new double[this->n]();
                    for (int j = 0;j<n;j++){
                        this->a[i][j] = B.a[i][j];
                    }
                }
                return *this;
            }
            // kompilator nie pozwala na przeładowanie operatora = poza klasą
            friend std::istream& operator>> (std::istream&s, matrix &a);
            friend std::ostream& operator<< (std::ostream&s, matrix a);
            double* operator[] (int i);
    };
#endif //_MATRIX_H
