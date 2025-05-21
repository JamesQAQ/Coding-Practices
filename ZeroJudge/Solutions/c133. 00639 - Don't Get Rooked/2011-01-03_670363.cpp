#include <iostream>
using namespace std;

char map[4][4];
int n,ans;
void spread(int x,int y,char d)
{
    char temp=map[x][y];
    int xx=x,yy=y;
    while (xx>=0)
    {
        if (map[xx][yy]=='X')
            break;
        if (map[xx][yy]==temp)
            map[xx][yy]=d;
        xx--;
    }
    xx=x+1;
    while (xx<n)
    {
        if (map[xx][yy]=='X')
            break;
        if (map[xx][yy]==temp)
            map[xx][yy]=d;
        xx++;
    }
    xx=x;
    yy=y-1;
    while (yy>=0)
    {
        if (map[xx][yy]=='X')
            break;
        if (map[xx][yy]==temp)
            map[xx][yy]=d;
        yy--;
    }
    yy=y+1;
    while (yy<n)
    {
        if (map[xx][yy]=='X')
            break;
        if (map[xx][yy]==temp)
            map[xx][yy]=d;
        yy++;
    }
}
void dfs(int x,int y,int sum)
{
    if (y==n)
    {
        y=0;
        x++;
    }
    if (x==n)
        return;
    if (map[x][y]=='.')
    {
        spread(x,y,sum+'A');
        if (sum+1>ans)
            ans=sum+1;
        dfs(x,y+1,sum+1);
        spread(x,y,'.');
    }
    dfs(x,y+1,sum);
}

int main()
{
    while (cin>>n)
    {
        if (n==0)
            break;
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                cin>>map[i][j];
        ans=0;
        dfs(0,0,0);
        cout<<ans<<endl;
    }
    return 0;
}
