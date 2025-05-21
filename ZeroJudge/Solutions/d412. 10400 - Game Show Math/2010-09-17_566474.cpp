#include <iostream>
#include <stdio.h>
using namespace std;

int p[100],ans,m;
bool r;
char c[99];
bool dfs (int sum,int n)
{
    if (n==m)
    {
        if (sum==ans)
        {
            for (int i=0;i<m-1;i++)
                printf("%d%c",p[i],c[i]);
            printf("%d=%d\n",p[m-1],ans);
            r=1;
            return 0;
        }
        else
            return 0;
    }
    if (r)
        return 0;
    if ((sum-p[n])>=-32000)
    {
        c[n-1]='-';
        dfs(sum-p[n],n+1);
    }
    if (r)
        return 0;
    if ((sum+p[n])<=32000)
    {
        c[n-1]='+';
        dfs(sum+p[n],n+1);
    }
    if (r)
        return 0;
    if (((sum*p[n])<=32000)&&(sum*p[n])>=-32000)
    {
        c[n-1]='*';
        dfs(sum*p[n],n+1);
    }
    if (r)
        return 0;
    if (sum%p[n]==0)
    {
        c[n-1]='/';
        dfs(sum/p[n],n+1);
    }
    if (r)
        return 0;
    return 1;
}
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        for (int i=0;i<n;i++)
        {
            r=0;
            scanf("%d",&m);
            for (int j=0;j<m;j++)
                scanf("%d",&p[j]);
            scanf("%d",&ans);
            if (dfs(p[0],1))
                puts("NO EXPRESSION");
        }
    }
    return 0;
}
