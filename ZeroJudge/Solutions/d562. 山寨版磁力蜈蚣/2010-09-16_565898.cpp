#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int n,a[100],l,r;
    while (scanf("%d",&n)!=EOF)
    {
        l=0;
        r=n-1;
        for (int i=0;i<n;i++)
            scanf("%d",&a[i]);
        while (1)
        {
            if (r-l<0)
                break;
            else
            {
                for (int i=l;i<=r;i++)
                    printf("%d ",a[i]);
                printf("\n");
                l++;
            }
            if (r-l<0)
                break;
            else
            {
                for (int i=r;i>=l;i--)
                    printf("%d ",a[i]);
                printf("\n");
                r--;
            }
        }
        printf("\n");
    }
    return 0;
}
