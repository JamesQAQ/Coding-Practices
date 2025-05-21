#include <iostream>
#include <deque>
using namespace std;

struct Node {int x,y,z,d;};
int s[6][3]={{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}};
bool finish;
int main()
{
    int l,r,c,sx,sy,sz;
    char map[32][32][32];
    while (cin>>l>>r>>c)
    {
        finish=0;
        if (l==0&&r==0&&c==0)
            break;
        for (int i=0;i<=l+1;i++)
            for (int j=0;j<=r+1;j++)
                for (int k=0;k<=c+1;k++)
                    map[i][j][k]='#';
        for (int i=1;i<=l;i++)
            for (int j=1;j<=r;j++)
                for (int k=1;k<=c;k++)
                {
                    cin>>map[i][j][k];
                    if (map[i][j][k]=='S')
                    {
                        sx=i;
                        sy=j;
                        sz=k;
                    }
                }
        Node a;
        deque <Node> Q;
        Q.clear();
        a.x=sx;
        a.y=sy;
        a.z=sz;
        a.d=0;
        Q.push_back(a);
        int ans;
        while (Q.empty()==0)
        {
            a=Q.front();
            Q.pop_front();
            int x=a.x,y=a.y,z=a.z,d=a.d;
            for (int i=0;i<6;i++)
            {
                int ix=x+s[i][0];
                int iy=y+s[i][1];
                int iz=z+s[i][2];
                if (map[ix][iy][iz]=='.')
                {
                    map[ix][iy][iz]='#';
                    a.x=ix;
                    a.y=iy;
                    a.z=iz;
                    a.d=d+1;
                    Q.push_back(a);
                }
                else if (map[ix][iy][iz]=='E')
                {
                    finish=1;
                    ans=d+1;
                    Q.clear();
                    break;
                }
            }
        }
        if (finish)
            cout<<"Escaped in "<<ans<<" minute(s)."<<endl;
        else
            cout<<"Trapped!"<<endl;
    }
    return 0;
}
