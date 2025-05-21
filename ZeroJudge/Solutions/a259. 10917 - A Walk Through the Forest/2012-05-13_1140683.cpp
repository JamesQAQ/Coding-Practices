#include <cstdio>
#include <vector>

struct Node {int to,w;} tmp;
std::vector <Node> path[1001];
int d[1001],Q[1000001],dp[1001];
bool inq[1001]={},run[1001];
int input(){
    char c=getchar();
    while (c>'9'||c<'0') c=getchar();
    int x=c-48;c=getchar();
    while (c<='9'&&c>='0') x=x*10+c-48,c=getchar();
    return x;
}
void spfa(int st,int n){
    for (int i=1;i<=n;i++)
        d[i]=-1;
    d[st]=0;
    int l=0,r=1;
    Q[0]=2;
    inq[2]=true;
    while (l<r){
        int x=Q[l++],p=path[x].size();
        inq[x]=false;
        for (int i=0;i<p;i++){
            int to=path[x][i].to;
            if (d[to]==-1||d[x]+path[x][i].w<d[to]){
                d[to]=d[x]+path[x][i].w;
                if (!inq[to]){
                    inq[to]=true;
                    Q[r++]=to;
                }
            }
        }
    }
}
int DP(int x){
    if (!run[x]){
        dp[x]=0;
        int p=path[x].size();
        for (int i=0;i<p;i++){
            int to=path[x][i].to;
            if (d[to]>d[x])
                dp[x]+=DP(to);
        }
        run[x]=true;
    }
    return dp[x];
}
int main()
{
    int n,m,a;
    while (n=input()){
        m=input();
        for (int i=1;i<=n;i++)
            path[i].clear(),run[i]=false;
        for (int i=0;i<m;i++){
            a=input();
            tmp.to=input();
            tmp.w=input();
            path[a].push_back(tmp);
            a^=tmp.to^=a^=tmp.to;
            path[a].push_back(tmp);
        }
        spfa(2,n);
        /*for (int i=1;i<=n;i++)
            printf("i %d %d\n",i,d[i]);*/
        dp[1]=1,run[1]=true;
        printf("%d\n",DP(2));
    }
}
