#include <cstdio>

int cost[202][202]={},v[202][202],d[202],Q[100000],f[202];
bool inq[202];
int spfa(int st,int ed){
    for (int i=st;i<=ed;i++)
        d[i]=-1;
    d[st]=0;
    f[st]=-1;
    Q[0]=st;
    int l=0,r=1;
    inq[st]=true;
    while (l<r){
        int x=Q[l];
        inq[x]=false;
        l++;
        for (int i=st;i<=ed;i++)
            if (v[x][i]){
                if (d[i]==-1||d[i]<d[x]+cost[x][i]){
                    d[i]=d[x]+cost[x][i];
                    f[i]=x;
                    if (!inq[i]){
                        inq[i]=true;
                        Q[r++]=i;
                    }
                }
            }
    }
    return d[ed];
}
int maxcost(int n,int num){
    int ans=0;
    while (1){
        int flow=spfa(0,num);
        if (flow<0)
            break;
        ans+=flow;
        int at=num;
        while (f[at]!=-1){
            v[f[at]][at]--;
            v[at][f[at]]++;
            at=f[at];
        }
    }
    return ans;
}
int main()
{
    int n;
    while (scanf("%d",&n),n){
        int num=2*n+1;
        for (int i=0;i<=num;i++)
            for (int j=0;j<=num;j++)
                v[i][j]=0;
        for (int i=1;i<=n;i++){
            v[0][i]=1;
            for (int j=1;j<=n;j++)
                scanf("%d",&cost[i][j+n]),cost[j+n][i]=-cost[i][j+n],v[i][j+n]=1;
        }
        for (int i=n+1;i<num;i++)
            cost[i][num]=0,v[i][num]=1;
        printf("%d\n",maxcost(n,num));
    }
}
