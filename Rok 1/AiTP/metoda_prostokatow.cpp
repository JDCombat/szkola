#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
    return pow(x, 2) - cos(x);
}

double trapez(double a, double b){
    const int N = 1000;
    double s, dx;
    int i;

    cout.precision(6);
    cout.setf(ios::fixed);

    cout << endl;

    s = 0;
    dx = abs(b - a) / N;
    for (i = 2; i <= N; i++)
        s += (f(a+(i*dx))+f(a+(i-1)*dx))/2 * dx;

    return s;
}

int main() {
    const int N = 1000;
    double xp, xk, s, dx;
    int i;

    cout.precision(6);
    cout.setf(ios::fixed);

    cout << "Podaj poczatek\n";
    cin >> xp;
    cout << "Podaj koniec\n";
    cin >> xk;

    cout << endl;

    s = 0;
    dx = abs(xk - xp) / N;
    for (i = 1; i <= N; i++)
        s += f(xp + i * dx) * dx;

    cout << "Wartosc wynosi: " << trapez(xp,xk) << endl;
}
//
// Created by Kozub Bartosz on 16.03.2023.
//
