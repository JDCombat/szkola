#include <iostream>
#include <cmath>
using namespace std;

double f(double x){
    return cos(x-1) - 3*x + 2;
}

double sieczne(double a, double b, double epsilon, int n){
    double pop=a, c=b;
    int i = 0;

    while(i <= n){
        i++;
        pop = c;
        c = a - f(a)*((b-a)/(f(b) - f(a)));
        b = a;
        a = c;
        if(fabs(a-b) < epsilon)
            return c;
        if(!(--n)){
            cout << "Przekroczony limit iteracji";
        }
    }
}


int main(){
    double e = 0.000000001;
    cout << sieczne(-100, 100, e, 100);
}