#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int n,a[50000];
    while (scanf("%d",&n)!=EOF)
    {
        if (n==0)
            break;
        for (int i=0;i<n;i++)
            scanf("%d",&a[i]);
        sort(a,a+n);
        int i=0,d;
        while (a[i]==a[i+1])
            i++;
        d=a[i+1]-a[i];
        for (;i<n-1;i++)
            if ((a[i+1]-a[i])!=d)
                if (a[i+1]!=a[i])
                    break;
        if (i==n-1)
            printf("Yes\n");
        else
            printf("No\n");
    }
    //system ("pause");
    return 0;
}
