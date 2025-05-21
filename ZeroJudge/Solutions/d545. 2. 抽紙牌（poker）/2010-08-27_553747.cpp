#include <iostream>
#include <stdio.h>
using namespace std;

char s[52];
int a[52];
bool compar(int i,int j)
{
    if (a[i]>a[j]) return 1;
    if (a[i]<a[j]) return 0;
    if (s[i]>s[j]) return 1;
    if (s[i]<s[j]) return 0;
}
int main()
{
    int n,m,t[52],x;
    while (scanf("%d",&n)!=EOF)
    {
        for (int i=0;i<n;i++)
            t[i]=i;
        for (int i=0;i<n;i++)
        {
            x=getchar();
            s[i]=getchar();
            scanf("%d",&a[i]);
        }
        sort(t,t+n,compar);
        scanf("%d",&m);
        printf("%c %d\n",s[t[m-1]],a[t[m-1]]);
    }
    return 0;
}
