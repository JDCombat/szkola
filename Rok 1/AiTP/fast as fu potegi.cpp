#include <iostream>

using namespace std;

long long power(int liczba, int wykladnik){
    if(liczba == 0 && wykladnik ==0){
        return -1;
    }

    if (wykladnik == 0){
        return 1;
    }

    if(wykladnik % 2 == 1){
        return liczba * power(liczba, wykladnik-1);
    }
    long long zwrot = power(liczba, wykladnik/2);
    zwrot *= zwrot;
    return zwrot;
}

long long powerITR(long long liczba, long long wykladnik){
    long long zwrot = 1;
    if(liczba == 0 && wykladnik ==0){
        return -1;
    }

    if(wykladnik == 1){
        return liczba;
    }

    if (wykladnik == 0){
        return 1;
    }

    while (wykladnik > 0){

    if(wykladnik % 2 == 1){
        zwrot *= liczba;
    }
    liczba *= liczba;
    wykladnik /= 2;
    }
    return zwrot;
}

int main(){
    cout << power(2, 50) << endl << endl;
    cout << powerITR(2,50);
}