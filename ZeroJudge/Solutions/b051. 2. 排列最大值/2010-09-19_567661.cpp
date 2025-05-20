#include <iostream>
#include <stdio.h>
using namespace std;

int n;
char a[1000][50];
bool cmp(int i,int j)
{
    int li=strlen(a[i]);
    int lj=strlen(a[j]);
    int mini=li+lj;
    for (int k=0;k<mini;k++)
    {
        if (a[i][k%li]>a[j][k%lj]) return 1;
        if (a[i][k%li]<a[j][k%lj]) return 0;
    }
    return 0;
}
int main()
{
    int t[1000];
    while (scanf("%d",&n)!=EOF)
    {
        for (int i=0;i<n;i++)
        {
            scanf("%s",&a[i]);
            t[i]=i;
        }
        stable_sort(t,t+n,cmp);
        for (int i=0;i<n;i++)
            printf("%s",a[t[i]]);
        printf("\n");
    }
    return 0;
}
