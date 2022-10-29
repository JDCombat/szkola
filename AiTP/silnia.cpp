#include <iostream>
using namespace std;
int b;
unsigned long long a;
int main(){
cout<<"Wpisz liczbe";
cin>>a;
b=a;
if(a==0){
    cout<<"Wynik to"<<a;
}
else{
    for(;b>1;b--){
        a=a*b;
        cout << a<< endl;
    }
}
return 0;
}



