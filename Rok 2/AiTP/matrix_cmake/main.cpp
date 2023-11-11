#include "headers/matrix.h"
#include "headers/function.h"
using namespace std;
int main(){
    int a,b;
    a = b = 5;
    matrix A(a,b,"Pierwsza macierz");
    cout << A;
    matrix B(a,b,"Druga macierz");
    cout << B;

    cout << A+B;

    int skalar = 3;

    cout << B*skalar;

    int e = 2,f = 3;
    matrix mA(e,f,"Pierwsza macierz do mnożenia");
    cout << mA;

    int g = 3,h = 2;
    matrix mB(g,h,"Druga macierz do mnożenia");
    cout << mB;

    cout << mA*mB;

    cout << mB.transpose();

    cout << "Wyznacznik pierwszej macierzy\n";
    cout << matrix::laplace(A) << endl;
    system("pause");
    return 0;
}




