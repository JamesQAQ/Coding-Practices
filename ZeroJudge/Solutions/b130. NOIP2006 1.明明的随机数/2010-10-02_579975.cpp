#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int n,a[100],p[100];
    while (scanf("%d",&n)==1)
    {
        for (int i=0;i<n;i++)
            scanf("%d",&a[i]);
        sort(a,a+n);
        int d=1001,sum=0;
        for (int i=0;i<n;i++)
            if (a[i]!=d)
            {
                p[sum]=a[i];
                d=a[i];
                sum++;
            }
        printf("%d\n",sum);
        for (int i=0;i<sum;i++)
            printf("%d ",p[i]);
        printf("\n");
    }
    return 0;
}
