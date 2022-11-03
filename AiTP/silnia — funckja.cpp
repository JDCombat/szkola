#include <iostream>
using namespace std;
unsigned long long silnia(int x);
int b;
unsigned long long a;
int main(){
cout<<"Wpisz liczbe";
cin>>a;
int w = silnia(a);
cout<<"wynik to"<< w << endl;
return 0;
}

unsigned long long silnia(int x){
 long long s=1;
 for(int i=1;i<=x;i++){
    s*=i;
 }
return s;
}



