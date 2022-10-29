#include <iostream>
using namespace std;

int main(){
    bool war = true;
    long long a, b, c;
    int w;
    char d, y;
    do{

        cout << "Podaj pierwsza liczbe" << endl;
        cin >> a;
        cout << "Podaj dzialanie" << endl;
        cin >> d;
        cout << "Podaj druga liczbe" << endl;
        cin >> b;
        w =1;
        switch (d)
        {
        case '+':
            c = a + b;
            cout << a << "+" << b << "=" << c << endl;
            break;
        case '-':
            c = a-b;
            cout <<a << "-" << b << "=" << c << endl;
            break;
        case '*':
            c = a*b;
            cout << a << "*" << b << "=" << c << endl;
            break;
        case '/':
            if(b!=0){
                c = a/b;
                cout << a << "/" << b << "=" << c << endl;
            }
            else
                cout << "Nie dielimy przez 0" << endl;
            break;
        case '^': 
            w = 1;
            while(b>0){
                w = w*a;
                b--;
            }
            cout << "Wynik wynosi " << w << endl;
            break;
        case '!':
            b=a;
            if(a==0){
                 cout<<"Wynik wynosi " << a << endl;
                }
            else{
                for(;b>1;b--){
                 a=a*b;
                }
                cout << "Wynik wynosi " << a << endl;
                }
            break;
        default:
            cout << "Podaj wlasciwe dzialanie" << endl;
            break;
        }
        cout << "Chcesz kontynuowac? Y/N" << endl;
        cin >> y;
    } while(y=='y' || y=='Y');
    return 0;
}