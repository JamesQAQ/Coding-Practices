#include <iostream>
using namespace std;

int main()
{
    long long int n;
    while (cin>>n)
    {
        if (n%2)
            cout<<(n/2-1)*(n/2)/4<<endl;
        else
            cout<<n*n/16<<endl;
    }
    return 0;
}
