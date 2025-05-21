#include <iostream>
using namespace std;

int tree[13],n;
bool path[13][13];
struct Node {int x,y;} dot[13][2];
void dfs(int x,int d)
{
    for (int i=0;i<n;i++)
        if (path[x][i])
        {
            path[x][i]=0;
            path[i][x]=0;
            tree[i]=d;
            dfs(i,d);
        }
}
bool test(int j,int k)
{
    int a[2],b[2],c[2],delta,x,y;
    a[0]=dot[j][0].y-dot[j][1].y;
    a[1]=dot[k][0].y-dot[k][1].y;
    b[0]=dot[j][1].x-dot[j][0].x;
    b[1]=dot[k][1].x-dot[k][0].x;
    c[0]=a[0]*dot[j][0].x+b[0]*dot[j][0].y;
    c[1]=a[1]*dot[k][0].x+b[1]*dot[k][0].y;
    delta=a[0]*b[1]-a[1]*b[0];
    x=c[0]*b[1]-c[1]*b[0];
    y=a[0]*c[1]-a[1]*c[0];
    if (delta==0)
    {
        if (x==0&&y==0)
        {
            if (dot[j][0].x<=max(dot[k][0].x,dot[k][1].x)&&dot[j][0].x>=min(dot[k][0].x,dot[k][1].x)&&dot[j][0].y<=max(dot[k][0].y,dot[k][1].y)&&dot[j][0].y>=min(dot[k][0].y,dot[k][1].y))
                return 1;
            if (dot[j][1].x<=max(dot[k][0].x,dot[k][1].x)&&dot[j][1].x>=min(dot[k][0].x,dot[k][1].x)&&dot[j][1].y<=max(dot[k][0].y,dot[k][1].y)&&dot[j][1].y>=min(dot[k][0].y,dot[k][1].y))
                return 1;
            if (dot[k][0].x<=max(dot[j][0].x,dot[j][1].x)&&dot[k][0].x>=min(dot[j][0].x,dot[j][1].x)&&dot[k][0].y<=max(dot[j][0].y,dot[j][1].y)&&dot[k][0].y>=min(dot[j][0].y,dot[j][1].y))
                return 1;
            if (dot[k][1].x<=max(dot[j][0].x,dot[j][1].x)&&dot[k][1].x>=min(dot[j][0].x,dot[j][1].x)&&dot[k][1].y<=max(dot[j][0].y,dot[j][1].y)&&dot[k][1].y>=min(dot[j][0].y,dot[j][1].y))
                return 1;
        }
    }
    else
    {
        if (x<=max(delta*dot[j][0].x,delta*dot[j][1].x)&&x>=min(delta*dot[j][0].x,delta*dot[j][1].x))
            if (x<=max(delta*dot[k][0].x,delta*dot[k][1].x)&&x>=min(delta*dot[k][0].x,delta*dot[k][1].x))
                if (y<=max(delta*dot[j][0].y,delta*dot[j][1].y)&&y>=min(delta*dot[j][0].y,delta*dot[j][1].y))
                    if (y<=max(delta*dot[k][0].y,delta*dot[k][1].y)&&y>=min(delta*dot[k][0].y,delta*dot[k][1].y))
                        return 1;
    }
    return 0;
}
int main()
{
    int t,b,c;
    cin>>t;
    for (int tt=0;tt<t;tt++)
    {
        if (tt)
            cout<<endl;
        cin>>n;
        for (int i=0;i<n;i++)
        {
            cin>>dot[i][0].x>>dot[i][0].y>>dot[i][1].x>>dot[i][1].y;
            tree[i]=i;
            for (int j=0;j<n;j++)
                path[i][j]=0;
        }
        for (int i=0;i<n-1;i++)
            for (int j=i+1;j<n;j++)
                if (test(i,j))
                    path[i][j]=path[j][i]=1;
        for (int i=0;i<n;i++)
            if (tree[i]==i)
                dfs(i,i);
        while (cin>>b>>c)
        {
            b--;
            c--;
            if (b==-1&&c==-1)
                break;
            cout<<((tree[b]==tree[c])?"":"NOT ")<<"CONNECTED\n";
        }
    }
    return 0;
}
