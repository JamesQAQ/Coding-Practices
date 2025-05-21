#include <iostream>
#include <cmath>
using namespace std;

struct Nodeint {int x,y;} n[30],m[30];
struct Nodedouble {double x,y;} node[10000];
int num=0,N,M,c[10000],cnum;
double eps=1e-6,areaN,areaM;
bool between(double x,double y,int l,int r)
{
    if (x<=max(n[l].x,n[l+1].x)&&x>=min(n[l].x,n[l+1].x))
        if (y<=max(n[l].y,n[l+1].y)&&y>=min(n[l].y,n[l+1].y))
            if (x<=max(m[r].x,m[r+1].x)&&x>=min(m[r].x,m[r+1].x))
                if (y<=max(m[r].y,m[r+1].y)&&y>=min(m[r].y,m[r+1].y))
                    return 1;
    return 0;
}
void connect(int l,int r)
{
    int a[2],b[2],c[2],delta;
    a[0]=n[l].y-n[l+1].y;
    a[1]=m[r].y-m[r+1].y;
    b[0]=n[l+1].x-n[l].x;
    b[1]=m[r+1].x-m[r].x;
    c[0]=n[l].x*a[0]+n[l].y*b[0];
    c[1]=m[r].x*a[1]+m[r].y*b[1];
    delta=a[0]*b[1]-a[1]*b[0];
    if (delta==0)
        return;
    node[num].x=(double)(c[0]*b[1]-c[1]*b[0])/(double)delta;
    node[num].y=(double)(a[0]*c[1]-a[1]*c[0])/(double)delta;
    if (between(node[num].x,node[num].y,l,r))
        num++;
}
void in_M(int x)
{
    double sum=0;
    for (int i=0;i<M;i++)
        sum+=fabs((m[i].x-n[x].x)*(m[i+1].y-n[x].y)-(m[i+1].x-n[x].x)*(m[i].y-n[x].y))/2;
    if (fabs(sum-areaM)<eps)
    {
        node[num].x=(double)n[x].x;
        node[num++].y=(double)n[x].y;
    }
}
void in_N(int x)
{
    double sum=0;
    for (int i=0;i<N;i++)
        sum+=fabs((n[i].x-m[x].x)*(n[i+1].y-m[x].y)-(n[i+1].x-m[x].x)*(n[i].y-m[x].y))/2;
    if (fabs(sum-areaN)<eps)
    {
        node[num].x=(double)m[x].x;
        node[num++].y=(double)m[x].y;
    }
}
bool length(int x,int y)
{
    double ax=node[c[cnum-1]].x-node[x].x,ay=node[c[cnum-1]].y-node[x].y;
    double bx=node[c[cnum-1]].x-node[y].x,by=node[c[cnum-1]].y-node[y].y;
    return ax*ax+ay*ay<bx*bx+by*by;
}
int main()
{
    scanf("%d",&N);
    for (int i=0;i<N;i++)
        scanf("%d %d",&n[i].x,&n[i].y);
    n[N]=n[0];
    areaN=0;
    for (int i=0;i<N;i++)
        areaN+=n[i].x*n[i+1].y-n[i].y*n[i+1].x;
    areaN=abs(areaN)/2;
    scanf("%d",&M);
    for (int i=0;i<M;i++)
        scanf("%d %d",&m[i].x,&m[i].y);
    m[M]=m[0];
    areaM=0;
    for (int i=0;i<M;i++)
        areaM+=m[i].x*m[i+1].y-m[i].y*m[i+1].x;
    areaM=abs(areaM)/2;
    for (int i=0;i<N;i++)
        for (int j=0;j<M;j++)
            connect(i,j);
    for (int i=0;i<N;i++)
        in_M(i);
    for (int i=0;i<M;i++)
        in_N(i);
    c[0]=0;
    cnum=1;
    while (1)
    {
        int next=0;
        for (int i=0;i<num;i++)
        {
            if (c[cnum-1]==i)
                continue;
            double cross=(node[next].x-node[c[cnum-1]].x)*(node[i].y-node[c[cnum-1]].y)-(node[i].x-node[c[cnum-1]].x)*(node[next].y-node[c[cnum-1]].y);
            if (cross>eps||fabs(cross)<eps&&length(next,i))//
                next=i;
        }
        c[cnum++]=next;
        if (fabs(node[next].x-node[0].x)<eps&&fabs(node[next].y-node[0].y)<eps)
            break;
    }
    //cout<<cnum<<endl;
    double ans=0;
    for (int i=0;i<cnum;i++)
        ans+=node[c[i]].x*node[c[i+1]].y-node[c[i+1]].x*node[c[i]].y;
    ans=fabs(ans)/2;
    cout.setf(ios::fixed);
    cout.precision(2);
    cout<<ans<<endl;
    //system("pause");
    return 0;
}
