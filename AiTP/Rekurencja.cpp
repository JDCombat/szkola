#include <iostream>
using namespace std;

unsigned long long fibonacci(int x);
long long silnia(int x);
float NWD(int x, int y);
int power(float x, int y);
unsigned int newton(int x, int y);
int main(){
    float a, b;
    cout << "Podaj liczbe do silni" << endl;
    cin >> a;
    cout << "Silnia wynosi " << silnia(a) << endl;

    cout << "Podaj liczbe do fibonacciego" << endl;
    cin >> a;
    cout << "Fibonacci wynosi " << fibonacci(a) << endl;

    cout << "Podaj liczby do NWD" << endl;
    cin >> a >> b;
    cout << "NWD wynosi " << NWD(a, b) << endl;

    cout << "Podaj liczbe do potegowania i wykładnik" <<endl;
    cin >> a >> b;
    cout << "Potega wynosi " << power(a, b) << endl;

    cout << "Podaj liczby do dwumianu newtona" << endl;
    cin >> a >> b;
    cout << "Dwumian wynosi " << newton(a, b) << endl;
}

long long silnia(int x){
    if(x==0)
        return 1;
    else if(x >= 1){
        return x*silnia(x-1);

    }
}

unsigned long long fibonacci(int x){
    if(x==0)
        return 0;
    else if(x==1)
        return 1;
    else if(x>1){
        return fibonacci(x-1)+fibonacci(x-2);
    }
}

float NWD(int x, int y){
    if(y==0)
        return x;
    else if(y>=1){
        return NWD(y, x%y);
    }
}

int power(float x, int y){
    if(x==0 && y==0){
        
    }
        
    else if(x!=0 && y==0)
        return 1;
    
    else if(y==1)
        return x;
    
    else if(y>1)
        return x*power(x, y-1);
}

unsigned int newton(int x, int y){
    if(y==0 || x==0)
        return 1;
    else if(y>0 || y<x)
        return silnia(x)/(silnia(y)*silnia(x-y));
}