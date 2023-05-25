#include <iostream>
#include <cmath>
using namespace std;

bool pierwsze(unsigned long long x);

int main(){
    long long a;
    cout << "Wpisz liczbe do sprawdzenia" << endl;
    cin >> a;
    if (pierwsze(a) == true){
        cout << "Liczba jest pierwsza";
    }
    else {
        cout << "Liczba nie jest pierwsza";
    }
}



bool pierwsze(unsigned long long x){

    if(x==2){
        return true;
    }

    if (x % 2 == 0){
        return false;
    }
    else{
    for (int i = 3;i<=sqrt(x);i+=2){

        if (x%i==0){
            return false;
            }

    }
        return true;
    }
}
