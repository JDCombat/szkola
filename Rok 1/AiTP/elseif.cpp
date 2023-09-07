#include <iostream>
using namespace std;

int main(){

    int dzien;
    cout << "Podaj liczbe od 1 do 7" << endl;
    cin >> dzien;

    if(dzien == 1){
        cout << "Poniedzialek";
    }
        else if(dzien == 2){
            cout << "Wtorek";
        }
            else if(dzien == 3){
            cout << "Sroda";
        }
            else if(dzien == 4){
            cout << "Czwartek";
        }
            else if(dzien == 5){
            cout << "Piatek";
        }
            else if(dzien == 6){
            cout << "Sobota";
        }
            else if(dzien == 7){
            cout << "Niedziela";
        }
        else
            cout << "Nie ma takiego dnia" << endl;
return 0;

}