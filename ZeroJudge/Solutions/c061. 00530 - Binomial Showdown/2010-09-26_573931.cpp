#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int n,m;
    long long int ans;
    while (scanf("%d %d",&n,&m))
    {
        if (n==0&&m==0)
            break;
        if (m>n/2)
            m=n-m;
        int i,j;
        for (i=1,j=n,ans=1;i<=m;i++,j--)
        {
            ans*=j;
            ans/=i;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
