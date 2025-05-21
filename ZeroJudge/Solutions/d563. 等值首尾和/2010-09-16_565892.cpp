#include <iostream>
#include <stdio.h>
using namespace std;

int a[100000],b[100000],sumb,sum,n;
bool search(int x,int l,int r)
{
    int mid=(l+r)/2;
    if (l<=r)
    {
        if (x>b[mid]) return search(x,mid+1,r);
        if (x<b[mid]) return search(x,l,mid-1);
        if (x==b[mid]) return 1;
    }
    return 0;
}
int main()
{
    while (scanf("%d",&n)!=EOF)
    {
        sumb=0;
        sum=0;
        scanf("%d",&a[0]);
        b[0]=a[0];
        for (int i=1;i<n;i++)
        {
            scanf("%d",&a[i]);
            b[i]=a[i]+b[i-1];
        }
        for (int i=n-1;i>=0;i--)
        {
            sumb+=a[i];
            if (search(sumb,0,n))
                sum++;
        }
        printf("%d\n",sum);
    }
    return 0;
}
