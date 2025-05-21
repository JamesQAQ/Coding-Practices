#include <iostream>
using namespace std;

int map[600][600],n,m,move[4][2]={{0,1},{1,0},{0,-1},{-1,0}},sum,dp[600];
struct Node {int x,y;};
struct MAP {int st,ed;} area[600][600];
bool get[600]={},have[600]={},use[600][600]={};
void dfs(int x,int y)
{
    use[x][y]=1;
    if (x==n)
    {
        if (!get[y])
        {
            get[y]=1;
            sum++;
        }
        area[x][y].st=min(area[x][y].st,y);
        area[x][y].ed=max(area[x][y].ed,y);
    }
    for (int i=0;i<4;i++)
    {
        int xx=x+move[i][0],yy=y+move[i][1];
        if (map[x][y]>map[xx][yy])
        {
            if (!use[xx][yy])
            {
                area[xx][yy].st=501;
                area[xx][yy].ed=0;
                dfs(xx,yy);
            }
            if (xx==n)
            {
                if (!get[yy])
                {
                    get[yy]=1;
                    sum++;
                }
                area[x][y].st=min(area[x][y].st,yy);
                area[x][y].ed=max(area[x][y].ed,yy);
            }
            if (area[xx][yy].st!=501)
            {
                area[x][y].st=min(area[x][y].st,area[xx][yy].st);
                area[x][y].ed=max(area[x][y].ed,area[xx][yy].ed);
            }
        }
    }
}
int main()
{
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            scanf("%d",&map[i][j]);
    sum=0;
    for (int i=1;i<=m;i++)
        dp[i]=501;
    for (int i=0;i<=n+1;i++)
        map[i][0]=map[i][m+1]=INT_MAX;
    for (int i=0;i<=m+1;i++)
        map[0][i]=map[n+1][i]=INT_MAX;
    for (int i=1;i<=m;i++)
    {
        if (!use[1][i])
        {
            area[1][i].st=501;
            area[1][i].ed=0;
            dfs(1,i);
        }
        if (area[1][i].st!=501)
            have[i]=1;
    }
    if (sum<m)
    {
        printf("0\n%d\n",m-sum);
        return 0;
    }
    dp[0]=0;
    for (int i=1;i<=m;i++)
        for (int j=1;j<=m;j++)
            if (have[j]&&area[1][j].ed>=i)
            {
                if (area[1][j].st>i)
                    break;
                for (int k=area[1][j].st;k<=i;k++)
                    dp[i]=min(dp[i],dp[k-1]+1);
            }
    printf("1\n%d\n",dp[m]);        
    //system("pause");
    return 0;
}
