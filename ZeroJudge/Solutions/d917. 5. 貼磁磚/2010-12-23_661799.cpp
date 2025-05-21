#include <iostream>
#include <algorithm>
using namespace std;

int up[500][500],nup[500],rightt[500][500],nright[500],map[500][500],xx[500],yy[500];
bool cmp(int i,int j)
{
    int p=nup[i]+nright[i],q=nup[j]+nright[j];
    return (p<q);
}
void insert(int x)
{
    xx[x]=0;
    yy[x]=0;
    for (int i=0;i<nup[x];i++)
        yy[x]=max(yy[x],yy[up[x][i]]+1);
    for (int i=0;i<nright[x];i++)
        xx[x]=max(xx[x],xx[rightt[x][i]]+1);
    while (map[xx[x]][yy[x]]!=-1)
        (xx[x]>yy[x])?xx[x]++:yy[x]++;
    map[xx[x]][yy[x]]=x;
}
int main()
{
    //freopen("in_5.txt","r",stdin);
    int n,w,a,b,c,t[500];
    while (scanf("%d",&n)!=EOF)
    {
        scanf("%d",&w);
        for (int i=0;i<n;i++)
        {
            nup[i]=0;
            nright[i]=0;
            t[i]=i;
        }
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                map[i][j]=-1;
        int lim=n*(n-1)/2;
        for (int i=0;i<lim;i++)
        {
            scanf("%d",&a);
            scanf("%d",&b);
            scanf("%d",&c);
            a--;
            b--;
            if (c)
                up[a][nup[a]++]=b;
            else
                rightt[a][nright[a]++]=b;
        }
        stable_sort(t,t+n,cmp);
        map[0][0]=t[0];
        xx[0]=0;
        yy[0]=0;
        for (int i=1;i<n;i++)
            insert(t[i]);
        int x=1,y=1;
        for (int i=0;i<n;i++)
        {
            if (xx[i]+1>x)
                x=xx[i]+1;
            if (yy[i]+1>y)
                y=yy[i]+1;
        }
        cout<<x*y*w*w<<endl;
    }
    return 0;
}
