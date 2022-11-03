#include <iostream>
using namespace std;
int dod(float x, float y);
int od(float x, float y);
int mno(float x, float y);
int dz(float x, float y);
long long si(int x);
int pot(int x, int y);
long long c;
int main(){
    bool war = true;
    float a, b;
    long long w;
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
            cout<<dod(a,b);
            break;
        case '-':
          cout<<od(a,b);
            break;
        case '*':
            cout<<mno(a,b);
            break;
        case '/':
            cout<<dz(a,b);
            break;
        case '^': 
            cout<<pot(a,b);
            break;
        case '!':
            cout<<si(a);
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

int dod(float x, float y){
    return x+y;
}
int od(float x, float y){
    return x-y;
}
int mno(float x, float y){
    return x*y;
}
int dz(float x, float y){
    if(y!=0){
                c = x/y;
                return c;
            }
            else
                cout << "Nie dielimy przez 0" << endl;
                return NULL;
            
}
long long si(int x){
    long long s=1;
 for(int i=1;i<=x;i++)
    s*=i;
return s;
}
int pot(int x, int y){
    long long w = 1;
            while(y>0){
                w = w*x;
                y--;
            }
            return w;
}