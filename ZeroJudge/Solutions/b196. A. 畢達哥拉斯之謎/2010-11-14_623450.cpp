#include <iostream>
using namespace std;

int ans[10000001]={};
int gcd (int m,int n)
{
    if (n==0)
        return m;
    return gcd(n,m%n);
}
int main()
{
    for (int i=1;i<2237;i++)
    {
        for (int j=i+1;j<3163;j+=2)
        {
            if (gcd(j,i)>1)
                continue;
            int p=i*i+j*j;
            if (p>=10000000)
                break;
            ans[p]++;
        }
    }
    for (int i=1;i<10000001;i++)
        ans[i]+=ans[i-1];
    int x;
    while (cin>>x)
    {
        if (x==0)
            break;
        cout<<ans[x]<<endl;
    }
    return 0;
}
