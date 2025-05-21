#include <cstdio>

int main()
{
    long long cat[26];
    cat[1]=1;
    for (int i=2;i<=25;i++)
        cat[i]=cat[i-1]*(4*i-2)/(i+1);
    int n;
    while (scanf("%d",&n)==1)
        printf("%lld\n",cat[n]);
}
