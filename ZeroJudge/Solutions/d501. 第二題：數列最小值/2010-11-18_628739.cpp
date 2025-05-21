#include <iostream>
#include <algorithm>
using namespace std;

int n,a[1000000],l,r;
int main()
{
    while (scanf("%d",&n)!=EOF)
    {
        for (int i=0;i<n;i++)
            scanf("%d",&a[i]);
        stable_sort(a,a+n);
        if (n%2)
        {
            l=a[n/2];
            r=l;
        }
        else
        {
            l=a[n/2-1];
            r=a[n/2];
        }
        printf("A=%d",l);
        for (int i=l+1;i<=r;i++)
            printf("、%d",i);
       printf("\n");
    }
    return 0;
}
