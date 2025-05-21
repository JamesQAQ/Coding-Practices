#include <iostream>
#include <stdio.h>
using namespace std;

int a[2],ans[20],d;
char s[3]="SL";
void dfs(int n)
{
    if (n==d)
    {
        for (int i=0;i<d;i++)
            printf("%C",s[ans[i]]);
        printf("\n");
    }
    else
    {
        for (int i=0;i<2;i++)
            if (a[i]>0)
            {
                ans[n]=i;
                a[i]--;
                dfs(n+1);
                a[i]++;
            }
    }
}
int main()
{
    while (scanf("%d",&a[0])!=EOF)
    {
        scanf("%d",&a[1]);
        d=a[0]+a[1];
        dfs(0);
        printf("\n");
    }
    return 0;
}
