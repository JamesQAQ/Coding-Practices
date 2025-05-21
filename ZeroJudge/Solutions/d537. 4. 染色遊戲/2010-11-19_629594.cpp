#include <iostream>
using namespace std;

struct ryb{bool r,y,b;};
int n,at[3][2],value[100][100],v[90];
ryb map[100][100],a[3];

int count(char c)
{
    int p=v[c],sum=0;
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            if (value[i][j]==p)
                sum++;
    return sum;
}
void combin(int x,int y,ryb z)
{
    map[x][y].r=map[x][y].r||z.r;
    map[x][y].y=map[x][y].y||z.y;
    map[x][y].b=map[x][y].b||z.b;
    value[x][y]=map[x][y].r*4+map[x][y].y*2+map[x][y].b;
}
bool spread(int k,int t)
{
    bool change=0;
    int x,y;
    x=at[k][0]-t;
    for (int i=-t;i<=t;i++)
    {
        y=at[k][1]+i;
        if (x<0)
            break;
        if (y>=0&&y<n)
        {
            change=1;
            combin(x,y,a[k]);
        }
    }
    x=at[k][0]+t;
    for (int i=-t;i<=t;i++)
    {
        y=at[k][1]+i;
        if (x>=n)
            break;
        if (y>=0&&y<n)
        {
            change=1;
            combin(x,y,a[k]);
        }
    }
    y=at[k][1]-t;
    for (int i=-t+1;i<t;i++)
    {
        x=at[k][0]+i;
        if (y<0)
            break;
        if (x>=0&&x<n)
        {
            change=1;
            combin(x,y,a[k]);
        }
    }
    y=at[k][1]+t;
    for (int i=-t+1;i<t;i++)
    {
        x=at[k][0]+i;
        if (y>=n)
            break;
        if (x>=0&&x<n)
        {
            change=1;
            combin(x,y,a[k]);
        }
    }
    return change;
}
int main()
{
    v['R']=4;
    v['Y']=2;
    v['B']=1;
    v['O']=6;
    v['G']=3;
    v['P']=5;
    v['D']=7;
    ryb zero;
    zero.r=0;
    zero.y=0;
    zero.b=0;
    int sum,ans,t;
    char c;
    bool change;
    while (cin>>n)
    {
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
            {
                map[i][j]=zero;
                value[i][j]=0;
            }
        for (int i=0;i<3;i++)
        {
            a[i]=zero;
            cin>>c>>at[i][0]>>at[i][1];
            int x=at[i][0],y=at[i][1];
            if (c=='R')
                a[i].r=1;
            else if (c=='Y')
                a[i].y=1;
            else
                a[i].b=1;
            combin(x,y,a[i]);
        }
        cin>>c;
        ans=count(c);
        t=1;
        change=1;
        while (change)
        {
            change=0;
            if (spread(0,t))
                change=1;
            if (spread(1,t))
                change=1;
            if (spread(2,t))
                change=1;
            sum=count(c);
            if (sum>ans)
                ans=sum;
            t++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
