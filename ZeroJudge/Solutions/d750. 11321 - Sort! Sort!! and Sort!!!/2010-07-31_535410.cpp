#include <iostream>
#include <stdio.h>
using namespace std;

int a[10000];
int n,m;
bool compar (int i,int j)
{
    if (a[i]%m<a[j]%m) return 1;
    if (a[i]%m>a[j]%m) return 0;
    if (a[i]%2>a[j]%2) return 1;
    if (a[i]%2<a[j]%2) return 0;
    if (a[i]%2==1)
    {
        if (a[i]>a[j]) return 1;
        if (a[i]<a[j]) return 0;
    }
    if (a[i]%2==0)
    {
        if (a[i]<a[j]) return 1;
        if (a[i]>a[j]) return 0;
    }
    return 1;
}
int main()
{
    while (scanf("%d",&n)!=EOF)
    {
        int t[n];
        scanf("%d",&m);
        if ((n==0)&&(m==0))
        {
            printf("0 0\n");
            break;
        }
        for (int i=0;i<n;i++)
            scanf("%d",&a[i]);
        for (int i=0;i<n;i++)
            t[i]=i;
        stable_sort(t,t+n,compar);
        printf("%d %d\n",n,m);
        for (int i=0;i<n;i++)
            printf("%d\n",a[t[i]]);
    }
    //system ("pause");
    return 0;
}
