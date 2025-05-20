#include <iostream>
using namespace std;

int ans[3][3]={{1,2,3},{4,5,6},{7,8,0}},now[3][3],s[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
bool ok;
bool finish()
{
    for (int i=0;i<3;i++)
        for (int j=0;j<3;j++)
            if (now[i][j]!=ans[i][j])
                return 0;
    return 1;
}
void dfs(int x,int y,int sum,int o)
{
    /*for (int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
            cout<<now[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
    getchar();*/
    if (ok)
        return;
    if (sum>20)
        return;
    if (finish())
    {
        ok=1;
        return;
    }
    for (int i=0;i<4;i++)
    {
        if (o==0&&i==2)
            continue;
        else if (o==2&&i==0)
            continue;
        else if (o==1&&i==3)
            continue;
        else if (o==3&&i==1)
            continue;
        int xx=x+s[i][0],yy=y+s[i][1];
        if (xx>=0&&xx<3&&yy>=0&&yy<3)
        {
            swap(now[x][y],now[xx][yy]);
            dfs(xx,yy,sum+1,i);
            swap(now[x][y],now[xx][yy]);
        }
    }
}
int main()
{
    int cases,si,sj;
    while (cin>>cases)
    {
        for (int t=0;t<cases;t++)
        {
            for (int i=0;i<3;i++)
                for (int j=0;j<3;j++)
                {
                    cin>>now[i][j];
                    if (now[i][j]==0)
                    {
                        si=i;
                        sj=j;
                    }
                }
            ok=0;
            for (int i=0;i<4;i++)
            {
                int xx=si+s[i][0],yy=sj+s[i][1];
                if (xx>=0&&xx<3&&yy>=0&&yy<3)
                {
                    swap(now[si][sj],now[xx][yy]);
                    dfs(xx,yy,1,i);
                    swap(now[si][sj],now[xx][yy]);
                }
            }
            if (ok)
                cout<<"Easy"<<endl;
            else
                cout<<"Hard"<<endl;
        }
    }
    return 0;
}
