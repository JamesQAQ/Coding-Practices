#include <iostream>
#include <deque>
using namespace std;
struct Node{int x,y,d;};

int main()
{
    char map[102][102];
    deque <Node> Q;
    int t,n,m,sx,sy,ex,ey,ans,s[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
    Node a;
    while (cin>>t)
        while (t-->0)
        {
            ans=0;
            cin>>n>>m>>sx>>sy>>ex>>ey;
            for (int i=0;i<=n+1;i++)
                for (int j=0;j<=m+1;j++)
                    map[i][j]='1';
            for (int i=1;i<=n;i++)
                for (int j=1;j<=m;j++)
                    cin>>map[i][j];
            a.x=sx;
            a.y=sy;
            a.d=1;
            Q.clear();
            Q.push_back(a);
            map[sx][sy]=='1';
            while (Q.empty()==0)
            {
                a=Q.front();
                Q.pop_front();
                int x=a.x,y=a.y,d=a.d;
                if (x==ex&&y==ey)
                {
                    ans=d;
                    break;
                }
                for (int i=0;i<4;i++)
                {
                    int xx=x+s[i][0],yy=y+s[i][1];
                    if (map[xx][yy]=='0')
                    {
                        map[xx][yy]='1';
                        a.x=xx;
                        a.y=yy;
                        a.d=d+1;
                        Q.push_back(a);
                    }
                }
            }
            cout<<ans<<endl;
        }
    return 0;
}
