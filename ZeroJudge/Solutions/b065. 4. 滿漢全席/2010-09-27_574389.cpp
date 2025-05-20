#include <iostream>
#include <stdio.h>
using namespace std;

bool use[15],finish,pa[15];
int th[15][2][2];
int n,m;

void dfs (int x)
{
    if (x==m)
    {
        finish=1;
        return;
    }
    for (int i=0;i<2;i++)
    {
        if (finish)
            return;
        if (!use[th[x][i][1]])
        {
            use[th[x][i][1]]=1;
            pa[th[x][i][1]]=th[x][i][0];
            dfs(x+1);
            use[th[x][i][1]]=0;
        }
        else if (pa[th[x][i][1]]==th[x][i][0])
            dfs(x+1);
    }
    return;
}
int main()
{
    int o;
    while (scanf("%d",&o)==1)
    {
        for (int i=0;i<o;i++)
        {
            scanf("%d %d",&n,&m);
            for (int j=0;j<m;j++)
            {
                char s[4];
                for (int k=0;k<2;k++)
                {
                    scanf("%s",s);
                    int len=strlen(s);
                    th[j][k][0]=(s[0]=='m')?1:0;
                    th[j][k][1]=(len>2)?(s[1]-48)*10+s[2]-49:s[1]-49;
                }
            }
            for (int j=0;j<n;j++)
                use[j]=0;
            finish=0;
            dfs(0);
            if (finish)
                puts("GOOD");
            else
                puts("BAD");
        }
    }
    return 0;
}
