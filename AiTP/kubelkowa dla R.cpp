#include <iostream>
#include <vector>
using namespace std;

void kubelkowe(int tab[]);

int main(){
    int n;
    double tab[10]{9.19,92,1423.2,213.4,4,3,6,32,6,43};

    double mini, maxi = tab[0];

    for (int i = 0 ; i<sizeof(tab);i++){
        if (tab[i]> maxi){
            maxi = tab[i];
        }
        else if(tab[i]<mini){
            mini = tab[i];
        }
    }

    for (int i = 0;i<sizeof(tab);i++){
        cout << tab[i] << endl;
    }

}



void kubelkowe(int tab[], int maxi, int mini){

vector <double> v;

for (int i = 0; i<sizeof(tab);i++){
    tab[i] = tab[i]/maxi;
}


}
