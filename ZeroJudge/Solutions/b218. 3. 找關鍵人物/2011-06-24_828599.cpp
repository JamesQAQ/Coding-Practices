#include <cstdio>
#include <vector>

int n,sum[20001],ans[20001];
std::vector <int> path[20001];
void count(int x,int f){
    int p=path[x].size();
    for (int i=0;i<p;i++){
        int to=path[x][i];
        if (f!=to){
            count(to,x);
            sum[x]+=sum[to];
        }
    }
}
void dfs(int x,int f){
    int p=path[x].size(),temp=n-sum[x];
    for (int i=0;i<p;i++){
        int to=path[x][i];
        if (to!=f){
            dfs(to,x);
            ans[x]+=temp*sum[to];
            temp+=sum[to];
        }
    }
}
int main()
{
    int a,b;
    while (scanf("%d",&n)==1){
        for (int i=1;i<=n;i++)
            path[i].clear(),sum[i]=1,ans[i]=0;
        for (int i=0;i<n-1;i++)
            scanf("%d %d",&a,&b),path[a].push_back(b),path[b].push_back(a);
        count(1,0);
        dfs(1,0);
        int anss=0,ansat;
        for (int i=1;i<=n;i++)
            if (ans[i]>anss)
                anss=ans[i],ansat=i;
        printf("%d %d\n",ansat,anss);
    }
    return 0;
}
