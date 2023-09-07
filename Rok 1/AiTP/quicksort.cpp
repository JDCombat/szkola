#include <iostream>
#include <cstdlib>
using namespace std;
int quicksort(int p, int k,int tab[]);
int main(){
    int tab[9];
    for(int i=0;i<10;i++){
        tab[i] = rand()%100;
        cout << tab[i]<< " ";
    }
    quicksort(0,9,tab);
    cout << endl << endl;
    for(int i=0; i<10;i++){
        cout << tab[i] << " ";
    }
    return 0;
}
int quicksort(int p, int k, int tab[]){
    int d = (p+k+((k+1)/2)) /3;
    int pivot = tab[d];
    int i = p;
    int j = k;
    while (i<=j){
    while (tab[i]<pivot)
    {
        i++;
    }
        while (tab[j]>pivot)
        {
            j--;
        }
        if (i<=j)
        {
            swap(tab[i], tab[j]);
            i++;
            j--;
        }
            else{
                break;
            }
        if (p<j)
        {
            quicksort(p,j,tab);
        }

        if (i<k)
        {
            quicksort(i,k,tab);
        }
        else{
                return 0;
            }
    }


}
