#include <iostream>
using namespace std;
int main(){
    for(int i=1;i<=10;i++){
        cout << "i=" << ++i << endl;
    }

        for(int i=1;i<=10;i++){
        cout << "i=" << i++ << endl;
    }

    int j=1;
    for(;;){
        if(j<=10){
            cout<< "j=" << j<< endl;
        }
        else
            break;
        j++;
    }

}
