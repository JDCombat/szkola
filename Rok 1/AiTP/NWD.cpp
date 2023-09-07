#include <iostream>
using namespace std;
int NWD(int x, int y);
int main(){
    int a,b;

    cout << "Wpisz pierwsza liczbe\n";
    cin >> a;
    cout << "Wpisz druga liczbe\n";
    cin >> b;

    
    cout << "NWD dla tych liczb to " << NWD(a,b)<<endl;



return 0;
}
int NWD(int x , int y){
    while(x!=y){
        if(x>y){
            x=x-y;
        }
        else {
            y=y-x;
        }

    }
    return x;
}
