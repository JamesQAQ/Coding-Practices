#include <iostream>
using namespace std;

int main()
{
    int cases,n,sum;
    while (cin>>cases)
        while (cases-->0)
        {
            sum=0;
            cin>>n;
            sum+=n/27;
            n%=27;
            sum+=n/9;
            n%=9;
            sum+=n/3;
            n%=3;
            sum+=n;
            cout<<sum<<endl;
        }
    return 0;
}
