#include <iostream>
#include <stdio.h>
using namespace std;

int map[502][502],len[502][502],down[1000][2],num,r,maxx;
bool use[502][502];
int s[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
void dfs(int x,int y)
{
    for (int i=0;i<4;i++)
    {
        int xx=x+s[i][0];
        int yy=y+s[i][1];
        if (map[xx][yy]>map[x][y])
        {
            if (use[xx][yy]||len[xx][yy]>len[x][y]+1)
            len[xx][yy]=len[x][y]+1;
            use[xx][yy]=0;
            dfs(xx,yy);
        }
    }
}
bool putin(int m)
{
    for (int j=1;j<=r;j++)
        for (int k=1;k<=r;k++)
        {
            int l;
            for (l=0;l<4;l++)
                if (map[j][k]>map[j+s[l][0]][k+s[l][1]])
                    break;
            if (l==4)
            {
                down[num][0]=j;
                down[num][1]=k;
                num++;
            }
            if (num>m)
                return 1;
        }
    return 0;
}
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        for (int i=0;i<n;i++)
        {
            num=0;
            maxx=0;
            scanf("%d",&r);
            int m;
            scanf("%d",&m);
            for (int j=1;j<=r;j++)
                for (int k=1;k<=r;k++)
                {
                    scanf("%d",&map[j][k]);
                    use[j][k]=1;
                    len[j][k]=0;
                }
            for (int j=0;j<=r+1;j++)
            {
                map[0][j]=2147483647;
                map[j][0]=2147483647;
                map[r+1][j]=2147483647;
                map[j][r+1]=2147483647;
                use[0][j]=0;
                use[j][0]=0;
                use[r+1][j]=0;
                use[j][r+1]=0;
                len[0][j]=0;
                len[j][0]=0;
                len[r+1][j]=0;
                len[j][r+1]=0;
            }
            if (putin(m))
            {
                puts("Impossible");
                continue;
            }
            for (int j=0;j<num;j++)
            {
                dfs(down[j][0],down[j][1]);
                use[down[j][0]][down[j][1]]=0;
            }
            for (int j=1;j<=r;j++)
                for (int k=1;k<=r;k++)
                    if (len[j][k]>maxx)
                        maxx=len[j][k];
            printf("%d\n",maxx);
        }
    }
    return 0;
}
