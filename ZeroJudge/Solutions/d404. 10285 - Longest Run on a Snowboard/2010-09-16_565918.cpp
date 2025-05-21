#include <iostream>
#include <stdio.h>
using namespace std;

int a[102][102],len[102][102],s[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
bool u[102][102];
int n,r,c;
void dfs(int x,int y)
{
    u[x][y]=0;
    for (int i=0;i<4;i++)
    {
        int x1=x+s[i][0],y1=y+s[i][1];
        if (a[x1][y1]<a[x][y])
        {
            if (u[x1][y1])
                dfs(x1,y1);
            if (len[x1][y1]>=len[x][y])
                len[x][y]=len[x1][y1]+1;
        }
    }
}
int main()
{
    string s;
    while (scanf("%d",&n)!=EOF)
    {
        int max=0;
        cin>>s;
        scanf("%d",&r);
        scanf("%d",&c);
        for (int i=0;i<=r+1;i++)
                a[i][0]=101;
        for (int i=0;i<=c+1;i++)
                a[0][i]=101;
        for (int i=0;i<=r+1;i++)
                a[i][c+1]=101;
        for (int i=0;i<=c+1;i++)
                a[r+1][i]=101;
        for (int i=1;i<=r;i++)
            for (int j=1;j<=c;j++)
            {
                scanf("%d",&a[i][j]);
                u[i][j]=1;
                len[i][j]=1;
            }
        for (int i=1;i<=r;i++)
            for (int j=1;j<=c;j++)
            {
                if (u[i][j])
                    dfs(i,j);
                if (len[i][j]>max)
                    max=len[i][j];
            }
        cout<<s;
        printf(": %d\n",max);
    }
    return 0;
}
