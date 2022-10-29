#include <iostream>
using namespace std;
int main(){
    int a,b;

    cout << "Wpisz pierwsza liczbe\n";
    cin >> a;
    cout << "Wpisz druga liczbe\n";
    cin >> b;

    while(a!=b){
        if(a>b){
            a=a-b;
        }
        else {
            b=b-a;
        }

    }
    cout << "NWD dla tych liczb to " << a;



return 0;
}
