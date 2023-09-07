#include <iostream>

using namespace std;

double bin_pow(double base, unsigned int exp){
    double res=1.0;

    while(exp>0){
        if (exp & 1){
            res*=base;
            base*=base;
            exp>>=1;
        }
    }
    return res;
}

double bin_rek(double base, unsigned int exp){
    if(exp==0) return 1;
    if(exp%2==1) return bin_rek(base,exp-1)*base;
    else{
        double a = bin_rek(base,exp>>1);
        return a*a;
    }
}


int main(){
    cout << bin_pow(2,50);
 //   cout << bin_rek(2,50);
}