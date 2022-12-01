#include <iostream>
using namespace std;
const int n = 10;
void sortowanie(int tab[]){
    int i;
    for(int k=1;k<n;k++){
        i=k;
        int temp=tab[i];

        while(i>0){
            if(temp<tab[i-1]){
                tab[i]=tab[i-1];
                tab[i-1]=temp;
            }
            i--;
        }
    }
}


int main(){
    int tab[n];
    for(int i = 0;i<(sizeof(tab)/4)+1;i++){
    int x = (rand()%n)+1;
    tab[i] = x;
}
cout << tab;
sortowanie(tab);
for(int i = 0; i<(sizeof(tab))+1;i++){
    cout << tab[i] << ", ";
}
}

