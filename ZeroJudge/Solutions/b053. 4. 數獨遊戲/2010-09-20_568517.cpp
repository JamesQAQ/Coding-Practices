#include <iostream>
#include <stdio.h>
using namespace std;

int n,a[9][9],num,space[81][2];
bool finish;
bool rtest(int i,int k)
{
    for (int j=0;j<3*n;j++)
        if (k==a[i][j])
            return 0;
    return 1;
}
bool ctest(int j,int k)
{
    for (int i=0;i<3*n;i++)
        if (k==a[i][j])
            return 0;
    return 1;
}
bool box(int i,int j,int k)
{
    int x,y;
    for (x=2;x>=0;x--)
        if (i>=n*x)
            break;
    for (y=2;y>=0;y--)
        if (j>=n*y)
            break;
    x*=n;
    y*=n;
    for (int o=0;o<n;o++)
        for (int l=0;l<n;l++)
            if (k==a[o+x][l+y])
                return 0;
    return 1;
}
void dfs(int x)
{
    if (x==num)
        finish=1;
    if (finish)
        return;
    for (int k=1;k<=3*n;k++)
    {
        if (finish)
            return;
        if (rtest(space[x][0],k))
            if (ctest(space[x][1],k))
                if (box(space[x][0],space[x][1],k))
                {
                    a[space[x][0]][space[x][1]]=k;
                    dfs(x+1);
                    if (finish)
                        return;
                    a[space[x][0]][space[x][1]]=0;
                }
    }
}
int main()
{
    while (scanf("%d",&n)!=EOF)
    {
        num=0;
        finish=0;
        for (int i=0;i<3*n;i++)
            for (int j=0;j<3*n;j++)
            {
                scanf("%d",&a[i][j]);
                if (a[i][j]==0)
                {
                    space[num][0]=i;
                    space[num][1]=j;
                    num++;
                }
            }
            dfs(0);
        if (finish)
            for (int i=0;i<3*n;i++)
            {
                for (int j=0;j<3*n;j++)
                    printf("%d ",a[i][j]);
                printf("\n");
            }
        else
            puts("NO SOLUTION");
    }
    return 0;
}
