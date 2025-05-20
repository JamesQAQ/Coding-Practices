#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    long long int a[46];
    a[0]=1;
    a[1]=1;
    for (int i=2;i<=45;i++)
        a[i]=a[i-1]+a[i-2];
    int n;
    while (scanf("%d",&n)==1)
        printf("%lld\n",a[n]);
    return 0;
}
