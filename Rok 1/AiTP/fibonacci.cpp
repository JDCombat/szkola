#include <iostream>
using namespace std;
unsigned long long fibonacci(unsigned int n);
int main(){

}

unsigned long long fibonacci(unsigned int n){

unsigned long long ppop=0, pop=1, f;
for(unsigned int i=2;i<=n;i++){
    f=ppop+pop;
    ppop=pop;
    pop=f;
}
return f;
}

long long silnia(int n){
    if(n==0)
    return 1;
    else
    return n*silnia(n-1);
}