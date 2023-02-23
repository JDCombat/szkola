#include <iostream>
#include <cmath> using namespace std; double funkcja(double x){
    return pow(x-5, 3);
} double miejsceZerowe(double a, double b){
    float e = 0.001f;
    float c = (a+b)/2;     if (funkcja(c) * funkcja(a) < 0)
        b = c;
    else
        a = c;
    if (fabs(a-b) < e && fabs(funkcja(a)-funkcja(b)) < e)
        return c;
    miejsceZerowe(a, b);
} int main(){
    cout << miejsceZerowe(-5, 10); }