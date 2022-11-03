#include <iostream>
using namespace std;
int sumal(int x, int y);
void suma2(int x, int y);
int suma3(void);
void suma4(void);
int x=2, y=5;

int main(){
int a, b;
cout<<"Podaj dwie liczby:/n";
cin>>a>>b;
//sumal
int wynik=sumal(a,b);
cout<<a<<"+"<<b<<"="<<wynik<<endl;
//aLbo
cout<<a<<"+"<<b<<"="<<sumal(a,b)<<endl;
//suma2
cout<<a<<"="<<b<<"=";
suma2(a,b);
//suma3
cout<<x<<"+"<<y<<"="<<suma3()<<endl;
// suma4
cout << x << "+" << y << "=";
suma4();


system("pause");
return 0;
}

int sumal(int x, int y){
    //int w;
    //w=x+Y;
    //return w;
return x+y;
}
void suma2(int x, int y){
cout<<x+y<<endl;
}
int suma3(void){
return x+y;
}
void suma4(void){
cout<<x+y<<endl;
}