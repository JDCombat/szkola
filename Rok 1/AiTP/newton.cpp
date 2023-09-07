#include <iostream>
#include <cmath>
using namespace std;

double f(double x){
    return pow(x, 2) - sin(2*x-1)-2;
}

double pochodna(double x){
    return 2*x -2*cos(1-2*x);
}

double newton(double b, double e){
    int licznik = 1000;
    double pop;
    do{
        pop=b;
        b-=f(b)/pochodna(b);
    } while ((fabs(b-pop)) >=e || fabs(f(b))>=e && --licznik > 0);

    if(licznik<=0){
        cout<< "Brak odpowiedzi\n";
        return -1;
    }

    return b;
}

int main(){
    double epsilon = 0.00000000000000000001;
    cout << "Miejsce zerowe funkcji to: " << newton(-2, epsilon);
}
