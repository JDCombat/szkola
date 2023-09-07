#include <iostream>
#include <cstdlib>
using namespace std;
void mergesort(int start, int end, int tab[], int t[]);
void merge(int start, int middle, int end, int tab[], int t[]);
int main(){
    int tab[10];
    for(int i=0;i<10;i++){
        tab[i] = rand()%100;
        cout << tab[i]<< " ";
    }

    int t[10];
    cout << endl << endl;
    mergesort(0, 9, tab, t);
    for(int i=0; i<10;i++){
        cout << tab[i] << " ";
    }
}
void mergesort(int start, int end, int tab[], int t[]){
    int middle;
    if(start!=end){
        middle = (start + end)/2;
        mergesort(start, middle, tab, t);
        mergesort(middle+1, end, tab, t);
        merge(start, middle, end, tab, t);
    }
    }
void merge(int start, int middle, int end, int tab[], int t[]){
    int i = start;
    int j = middle+1;
    int k = i;
    for(int p=start;p<=end;p++){
        t[p] = tab[p];
    }
    while(i<=middle && j<=end){
        if(t[i] < t[j]){
            tab[k] = t[i];
            i++;
        }
        else{
            tab[k] = t[j];
            j++;
        }
        k++;
    }
    while(i<=middle){
        tab[k] = t[i];
        i++;
        k++;
    }
}

