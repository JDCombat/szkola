#include <iostream>
using namespace std;
int NWD(int x, int y);
int c;
int main(){
    int a,b;

    cout << "Wpisz pierwsza liczbe\n";
    cin >> a;
    cout << "Wpisz druga liczbe\n";
    cin >> b;
    cout << "NWD Wynosi " << NWD(a,b)<< endl;

    


}
int NWD(int x, int y){
    while(y!=0){

        c=x%y;
        x=y;
        y=c;

    }
    return x;
}
