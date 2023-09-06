#include <iostream>
using namespace std;
void Increment_1(int &a, int &b);
void Increment_2(int* a, int* b);
int main(){
    cout << endl;
    int a = 5;
    int* ptr = &a;

    cout << ptr << endl;
    cout << *ptr << endl;

    *ptr = 7;
    cout << *ptr << endl;

    int b = 2;
    ptr = &b;
    cout << ptr << endl;
    cout << *ptr << endl;
    cout << b << endl;

    int tablica[5] = { 10, 200, 453, 123, 645 };
    int *t = tablica;
    cout << *t << endl
        << t[0] << endl
        << t[1] << endl
        << t[2] << endl
        << t[3] << endl
        << t[4] << endl;

        t+=3;
        cout << *t << endl;
        t+=1000;
        cout << *t << endl;


    int x = 20;
    int y = 10;
    Increment_1(x,y);
    cout << x << "\t" << y << endl;
    Increment_2(&x,&y);
}
void Increment_1(int &a, int &b){
    a++;
    b++;
    return;
}

void Increment_2(int* a, int* b){
    int y=++*a;
    int z=++*b;

    cout << y << "\t" << z << endl;
}
