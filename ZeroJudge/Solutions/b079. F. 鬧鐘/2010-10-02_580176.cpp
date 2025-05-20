#include <iostream>
#include <stdio.h>
using namespace std;

long long int a[1000001];
int main()
{
    a[1]=1;
    a[2]=1;
    for (int i=3;i<1000001;i++)
        a[i]=a[i-a[i-1]]+a[i-1-a[i-2]];
    int n;
    while (scanf("%d",&n)==1)
    {
        if (n==0)
            break;
        printf("%lld\n",a[n]);
    }
    return 0;
}
