#include <iostream>
#include <stdio.h>
using namespace std;

int search(int a[],int x,int l,int r)
{
    if (r>=l)
    {
        int mid=(l+r)/2;
        if (x<a[mid]) return search(a,x,l,mid-1);
        if (x>a[mid]) return search(a,x,mid+1,r);
        if (x==a[mid]) return mid;
    }
    return -1;
}
int main()
{
    int n,k,a[100000],x,r;
    while (scanf("%d",&n)!=EOF)
    {
        scanf("%d",&k);
        for (int i=0;i<n;i++)
            scanf("%d",&a[i]);
        for (int i=0;i<n;i++)
        {
            scanf("%d",&x);
            r=search(a,x,0,n);
            if (r>=0)
                printf("%d\n",r+1);
            else
                printf("0\n");
        }
    }
    //system("pause");
    return 0;
}
