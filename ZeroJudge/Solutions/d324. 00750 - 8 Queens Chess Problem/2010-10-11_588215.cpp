#include <iostream>
using namespace std;

int ans[8],sum,sy;
bool map[8][8];
void spread(int x,int y)
{
    for (int i=0;i<8;i++)
    {
        map[i][y]=1;
        map[x][i]=1;
    }
    int xx,yy;
    xx=x-1;
    yy=y-1;
    while (xx>=0&&yy>=0)
        map[xx--][yy--]=1;
    xx=x+1;
    yy=y-1;
    while (xx<8&&yy>=0)
        map[xx++][yy--]=1;
    xx=x-1;
    yy=y+1;
    while (xx>=0&&yy<8)
        map[xx--][yy++]=1;
    xx=x+1;
    yy=y+1;
    while (xx<8&&yy<8)
        map[xx++][yy++]=1;
}
void dfs(int x)
{
    if (x==8)
    {
        sum++;
        cout<<" "<<sum<<"      "<<ans[0];
        for (int i=1;i<8;i++)
            cout<<" "<<ans[i];
        cout<<endl;
        return;
    }
    if (x!=sy-1)
    {
        for (int i=0;i<8;i++)
            if (!map[i][x])
            {
                spread(i,x);
                ans[x]=i+1;
                dfs(x+1);
                memset(map,0,sizeof(map));
                spread(ans[sy-1]-1,sy-1);
                for (int j=0;j<x;j++)
                    spread(ans[j]-1,j);
            }
    }
    else
    {
        spread(ans[sy-1]-1,sy-1);
        dfs(x+1);
        memset(map,0,sizeof(map));
        for (int j=0;j<x;j++)
            spread(ans[j]-1,j);
    }       
}
int main()
{
    int t,x;
    cin>>t;
    for (int i=0;i<t;i++)
    {
        memset(map,0,sizeof(map));
        cin>>x>>sy;
        for (int i=0;i<8;i++)
            ans[i]=9;
        ans[sy-1]=x;
        spread(x-1,sy-1);
        sum=0;
        cout<<"SOLN       COLUMN"<<endl;
        cout<<" #      1 2 3 4 5 6 7 8"<<endl<<endl;
        dfs(0);
}
    return 0;
}
