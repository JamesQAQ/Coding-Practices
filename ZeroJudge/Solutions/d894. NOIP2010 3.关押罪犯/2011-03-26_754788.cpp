#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int n,m,AB[20001];
struct EDGE {int x,y,w;} edge[100000];
struct Node {int to,w,no;};
deque <Node> path[20001];
bool cmp(EDGE i,EDGE j)
{
    return i.w>j.w;
}
bool search(int x,int limit)
{
    int p=path[x].size();
    for (int i=0;i<p;i++)
    {
        if (path[x][i].no>=limit)
            continue;
        int to=path[x][i].to;
        if (AB[to]==AB[x])
            return 0;
        if (AB[to]==0)
        {
            AB[to]=3-AB[x];
            if (!search(to,limit))
                return 0;
        }
    }
    return 1;
}
bool ok(int mid)
{
    for (int i=1;i<=n;i++)
        AB[i]=0;
    for (int i=1;i<=n;i++)
        if (AB[i]==0)
        {
            AB[i]=1;
            if (!search(i,mid))
                return 0;
        }
    return 1;
}
int main()
{
    scanf("%d %d",&n,&m);
    for (int i=0;i<m;i++)
        scanf("%d %d %d",&edge[i].x,&edge[i].y,&edge[i].w);
    stable_sort(edge,edge+m,cmp);
    for (int i=0;i<m;i++)
    {
        int x=edge[i].x,y=edge[i].y;
        Node e;
        e.w=edge[i].w;
        e.no=i;
        e.to=y;
        path[x].push_back(e);
        e.to=x;
        path[y].push_back(e);
    }
    int l=0,r=m,mid;
    while (l<=r)
    {
        mid=(l+r)/2;
        //printf("mid:%d\n",mid);
        if (ok(mid))
            l=mid+1;
        else
            r=mid-1;
    }
    if (r>=m)
        puts("0");
    else
        printf("%d\n",edge[r].w);
    //system("pause");
    return 0;
}
