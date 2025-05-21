#include <stdio.h>
#include <vector>
#define MAX 500001

struct EDGE{
    int v,w;
} ;
std::vector <EDGE> path[MAX];
int d[MAX],Q[4*MAX];
bool inq[MAX];
int spfa(int st,int ed){
    for (int i=st;i<=ed;i++)
        d[i]=-1,inq[i]=false;
    d[st]=0;
    inq[st]=true;
    int l=0,r=0;
    Q[r++]=st;
    while (l<r){
        int x=Q[l++],p=path[x].size();
        inq[x]=false;
        for (int i=0;i<p;i++){
            int to=path[x][i].v;
            if (d[to]==-1||d[x]<d[to]-path[x][i].w){
                d[to]=d[x]+path[x][i].w;
                if (!inq[to])
                    Q[r++]=to,inq[to]=true;        
            }
        }        
    }
    return d[ed];
}
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;i++)
        path[i].clear();
    int a;
    EDGE tmp;
    for (int i=0;i<m;i++){
        scanf("%d %d %d",&a,&tmp.v,&tmp.w);
        path[a].push_back(tmp);
    }
    printf("%d\n",spfa(1,n));
}
