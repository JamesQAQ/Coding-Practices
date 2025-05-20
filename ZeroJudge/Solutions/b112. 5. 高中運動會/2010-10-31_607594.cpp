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
    int n,a[500];
    while (cin>>n)
    {
        for (int i=0;i<n;i++)
            cin>>a[i];
        int big,small;
        for (int i=0;i<n-1;i++)
        {
            big=max(a[i],a[i+1]);
            small=min(a[i],a[i+1]);
            a[i+1]=gcd(big,small);
        }
        cout<<a[n-1]<<endl;
    }
    return 0;
}
