#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int n,a,b;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        scanf("%d",&a);
        scanf("%d",&b);
        a=(a%2==0)?a+1:a;
        b=(b%2==0)?b-1:b;
        printf("Case %d: %d\n",i+1,((a+b)*((b-a)/2+1))/2);
    }
    return 0;
}
