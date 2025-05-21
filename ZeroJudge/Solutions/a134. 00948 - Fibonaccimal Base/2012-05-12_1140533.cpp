#include <cstdio>

int main()
{
    int cases,n,f[100]={1,1},p;
    for (int i=2;(p=f[i-1]+f[i-2])<=100000000;i++)
        f[i]=p;
    scanf("%d",&cases);
    while (cases--){
        scanf("%d",&n);
        printf("%d = ",n);
        bool first=true;
        for (int i=38;i>=1;i--){
            if (f[i]<=n)
                n-=f[i],putchar('1'),first=false;
            else if (!first)
                putchar('0');
        }
        puts(" (fib)");
    }
}
