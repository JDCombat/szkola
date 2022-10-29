#include <iostream>
using namespace std;
int main(){
    int a,b,c;

    cout << "Wpisz pierwsza liczbe\n";
    cin >> a;
    cout << "Wpisz druga liczbe\n";
    cin >> b;

    while(b!=0){

        c=a%b;
        a=b;
        b=c;

    }
    cout << "NWD wynosi " << a;


}
