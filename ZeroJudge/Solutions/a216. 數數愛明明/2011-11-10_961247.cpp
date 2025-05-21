#include <cstdio>

int main()
{
    long long f[30001],g[30001];
    f[1]=g[1]=1;
    for (int i=2;i<=30000;i++)
        f[i]=f[i-1]+i,g[i]=f[i]+g[i-1];
    int n;
    while (scanf("%d",&n)==1)
        printf("%lld %lld\n",f[n],g[n]);
    return 0;
}
