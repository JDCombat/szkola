#include <iostream>

using namespace std;
double pierwiastek(double x, double a, double b);
int main(){
int inp;
cout << "Podaj liczbe do pierwiastkowania" << endl;
cin >> inp;
cout << pierwiastek(inp, inp, 1);
}

double pierwiastek(double x, double a, double b){
    double e = 0.001;
    if (a - b<e){
        return a;
    } 
    else{
        a = (a+b)/2;
        b = x/a;
        pierwiastek(x, a, b);
    }
}