#include <iostream>
#include <stdio.h>
using namespace std;

bool use[21];
int start,end,n;
double map[21][21],ans;
void dfs(int x,double sum)
{
    if (x==end)
    {
        ans*=1-sum;
        return;
    }
    for (int i=1;i<=n;i++)
        if (x!=i)
            if (map[x][i]>0&&use[i])
            {
                use[i]=0;
                dfs(i,sum*map[x][i]);
                use[i]=1;
            }
}
int main()
{
    while (scanf("%d",&n)==1)
    {
        ans=1.0;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                scanf("%lf",&map[i][j]);
        scanf("%d %d",&start,&end);
        for (int i=1;i<=n;i++)
            use[i]=1;
        use[start]=0;
        dfs(start,1.0);
        printf("%.5lf\n",1-ans);
    }
    return 0;
}
