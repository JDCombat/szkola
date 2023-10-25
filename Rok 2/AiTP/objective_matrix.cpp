#include <iostream>
using namespace std;

class matrix{
    protected:
        double **a;
        int m, n;
        string name;
    public:
        matrix();
        void create(int x, int y);
        matrix(int x, int y, string N);
        void fill();
        void show();
        void set(int i, int j, double r);
        double get(int i, int j);
        int get_m();
        int get_n();
};

int main(){


}

matrix::matrix() {};
void matrix::create(int x, int y){
    
}
matrix::matrix(int x, int y, string N){

}