#ifdef _MATRIX_H
#define _MATRIX_H

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
                throw std::invalid_argument("Macierz musi być o rozmiarach MxM");
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
        matrix& operator= (const matrix &B);
        friend istream& operator>> (istream&s, matrix &a);
        friend ostream& operator<< (ostream&s, matrix a);
        double* operator[] (int i){
            return this->a[i];
        }
};
#endif