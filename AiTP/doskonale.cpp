#include<iostream>
using namespace std;
 
int main()
{
    int n;
        
        cout<<"Podaj liczbę: ";
        cin>>n;
        int liczba = n;        
        cout<<"Czynniki pierwsze liczby "<<n<<": ";
        int sum = 1;
        int k=2; 
        while(n>1)
        {
                while(n%k==0) 
                {
                        cout<<k<<" ";
                        sum += k;
                        n/=k;
                }
                ++k;
        }
        cout << endl << sum << endl;
        if (sum == liczba){
            cout << "To jest liczba doskonala";
    }
        else {
        cout << "To nie jest liczba doskonala";
        }
        return 0;
}
