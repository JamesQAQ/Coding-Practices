#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

int n,m,dfn[30001],low[30001],sum[30001],cut[30001];
vector <int> path[30001];
bool v[30001];
void dfs(int pre,int x,int d){
    dfn[x]=low[x]=d;
    v[x]=1;
    sum[x]=1;
    int count=0,p=path[x].size();
    for (int i=0;i<p;i++){
        int to=path[x][i];
        if (v[to]&&to!=pre)
            low[x]=min(low[x],dfn[to]);
        if (!v[to]){
            dfs(x,to,d+1);
            count++;
            sum[x]+=sum[to];
            low[x]=min(low[x],low[to]);
            if ((dfn[x]==0&&count>1)||(dfn[x]!=0&&dfn[x]<=low[to]))
                cut[x]+=sum[to];
        }
    }
}
int main()
{
    int a,b,start;
    while (scanf("%d %d",&n,&m)==2){
        for (int i=1;i<=n;i++){
            path[i].clear();
            cut[i]=0;
            v[i]=0;
        }
        for (int i=0;i<m;i++){
            scanf("%d %d",&a,&b);
            path[a].push_back(b);
            path[b].push_back(a);
        }
        scanf("%d",&start);
        dfs(0,start,0);
        int mini=sum[start],ans=0;
        for (int i=1;i<=n;i++)
            if (i!=start&&sum[start]-cut[i]<mini){
                mini=sum[start]-cut[i];
                ans=i;
            }
        if (ans)
            printf("%d %d\n",ans,mini);
        else
            puts("0");
    }
    return 0;
}
