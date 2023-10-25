#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;
int **creatematrix(int m)
{
    int **tab;
    tab=new int*[m];
    for(int i=0;i<m;i++)
        tab[i]=new int[m];
    for(int i=0;i<m;i++)
        for(int j=0; j<m; j++)
            tab[i][j] = rand() % 10;
    return tab;
}
int **emptymatrix(int m)
{
    int **tab;
    tab=new int*[m];
    for(int i=0;i<m;i++)
        tab[i]=new int[m];
    for(int i=0;i<m;i++)
        for(int j=0; j<m; j++)
            tab[i][j] = 0;
    return tab;
}

void print(int m, int** tab)
{
    cout<<"\n";
    for(int i=0; i<m; i++)
    {

        for(int j=0; j<m; j++)
            cout<<tab[i][j]<<"\t";
    cout<<"\n";
    }
}

int** minor(int** tab, int m, int i, int j)
{
    int**minor = emptymatrix(m-1);
    for(int k=0; k<m-1; k++)
        for(int l=0; l<m-1; l++)
        {
            if(l>=j)
                minor[k][l] = tab[k+1][l+1];
            else{
                minor[k][l] = tab[k+1][l];
            }
        }
    print(m-1, minor);
    return minor;
}
int laplace(int** tab, int m)
{
    if(m==1)
        return tab[0][0];
    int wyznacznik = 0;
    for(int j=0; j<m; j++)
        wyznacznik+= pow(-1, j) * tab[0][j] * laplace(minor(tab,m,0,j), m-1);
    return wyznacznik;
}

int main()
{
    int m,x,y,skala;
    cout<<"podaj ilosc rzedow i kolumn macierzy: ";
    cin>>m;
    int **tab1 = creatematrix(m);
    print(m,tab1);
    cout<<laplace(tab1, m);
    return 0;
}
