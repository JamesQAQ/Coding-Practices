#include <iostream>
using namespace std;

int gcd(int m,int n)
{
    if (n==0)
        return m;
    return gcd(n,m%n);
}
int main()
{
    int a,b,cases;
    while (cin>>cases)
        while (cases-->0)
        {
            cin>>a>>b;
            cout<<a*b/gcd(max(a,b),min(a,b))<<endl;
        }
    return 0;
}
