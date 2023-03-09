#include <iostream>
#include <cmath>
using namespace std;
double f(double x){
    return cos(x-1) - 3*x + 2;
}
double bisekcja_rek(double a, double b){
    double c = (a+b)/2;
    float e = 0.000001;
    if(fabs(a-b)>=e || fabs(f(b) - f(a)) >= e){
        if((f(a) * f(c)) <= 0){
            return bisekcja_rek(a, c);
        }
        else{
            return bisekcja_rek(c, b);
        }
    }
    else{
        return c;
    }
}

double bisekcja_it(double a, double b){
    double e = 0.000001;
    double c;
    while(fabs(a-b)>=e || fabs(f(b) - f(a)) >= e){
        c = (a+b)/2;

        if((f(a) * f(c)) <= 0){
            b = c;
        }
        else{
            a = c;
        }
    }
    return c;
}

double falsi(double a, double b, double epsilon){
    double c = a - f(a)*((b-a)/(f(b) - f(a)));
    while(fabs(f(c)) > epsilon){
        if (f(a)*f(c) < 0){
            b = c;
        }
        else{
            a = c;
        }
        c = a - f(a)*((b-a)/(f(b) - f(a)));
    }
    return c;
}

int main(){
    double e = 0.0000000001;
    cout << bisekcja_rek(0,2) << endl << endl;
    cout << bisekcja_it(0,2) << endl << endl;

    cout << fals(-1000, 1000, e);
    }