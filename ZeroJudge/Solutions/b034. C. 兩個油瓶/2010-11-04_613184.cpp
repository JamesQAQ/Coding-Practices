#include <iostream>
using namespace std;

int gcd (int m,int n)
{
    if (n==0)
        return m;
    return gcd(n,m%n);
}
int main()
{
    int a,b,c;
    while (cin>>a>>b>>c)
    {
        if (a==0&&b==0&&c==0)
            break;
        int big=max(a,b);
        int small=min(a,b);
        if (c%gcd(big,small)==0)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}
