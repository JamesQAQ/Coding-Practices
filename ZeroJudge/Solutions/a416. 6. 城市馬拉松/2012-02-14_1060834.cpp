#include <cstdio>
#include <vector>
#include <queue>

struct Node {int to,w;} tmp;
int oddnum=0,odd[30],st,ed,n,degree[1001],dis[1001][1001],dp[4200000];
bool run[4200000]={};
std::vector <Node> path[1001];
bool inq[1001];
void spfa(int st,int d[]){
    for (int i=1;i<=n;i++)
        d[i]=-1,inq[i]=false;
    d[st]=0,inq[st]=true;
    std::queue <int> Q;
    Q.push(st);
    while (!Q.empty()){
        int x=Q.front(),p=path[x].size();
        Q.pop();
        inq[x]=false;
        for (int i=0;i<p;i++){
            int to=path[x][i].to,w=path[x][i].w;
            if (d[to]==-1||d[to]-w>d[x]){
                d[to]=d[x]+w;
                if (!inq[to]){
                    inq[to]=true;
                    Q.push(to);
                }
            }
        }
    }
}
int dfs(int x){
    if (!run[x]){
        dp[x]=2147483647;
        for (int i=0,j=1;i<oddnum;i++,j<<=1)
            if (j&x)
                for (int k=i+1,l=1<<k;k<oddnum;k++,l<<=1)
                    if (l&x){
                        int v=dfs(x-j-l)+dis[odd[i]][odd[k]];
                        if (v<dp[x])
                            dp[x]=v;
                    }
        run[x]=true;
    }
    return dp[x];
}
int main()
{
    int m,a,ans=0;
    scanf("%d %d %d %d",&n,&m,&st,&ed);
    for (int i=1;i<=n;i++)
        path[i].clear(),degree[i]=0;
    for (int i=0;i<m;i++){
        scanf("%d %d %d",&a,&tmp.to,&tmp.w);
        ans+=tmp.w;
        path[a].push_back(tmp),degree[a]++;
        a^=tmp.to^=a^=tmp.to;
        path[a].push_back(tmp),degree[a]++;
    }
    if ((degree[st]&1)==0)
        spfa(st,dis[st]);
    if ((degree[ed]&1)==0)
        spfa(ed,dis[ed]);
    for (int i=1;i<=n;i++)
        if (degree[i]&1){
            odd[oddnum++]=i;
            spfa(i,dis[i]);
        }
    run[0]=true,dp[0]=0;
    if ((degree[st]&1)==0&&(degree[ed]&1)==0){
        odd[oddnum++]=st,odd[oddnum++]=ed;
        ans+=dfs((1<<oddnum)-1);
    }
    else if ((degree[st]&1)&&(degree[ed]&1)){
        for (int i=0;i<oddnum;i++)
            if (odd[i]==st||odd[i]==ed){
                for (int j=i;j<oddnum;j++)
                    odd[j]=odd[j+1];
            }
        oddnum-=2;
        ans+=dfs((1<<oddnum)-1);
    }
    else{
        //puts("I can't solve!");
        if (degree[ed]&1)
            st^=ed^=st^=ed;
        for (int i=0;i<oddnum;i++)
            if (odd[i]==st){
                odd[i]=ed;
                break;
            }
        ans+=dfs((1<<oddnum)-1);
    }
    printf("%d\n",ans);
}
