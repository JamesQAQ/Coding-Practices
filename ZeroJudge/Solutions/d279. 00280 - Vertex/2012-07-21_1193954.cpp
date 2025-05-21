#include <cstdio>
#include <vector>

std::vector <int> path[101];
bool visit[101][101];
int ans[101];
void dfs(int x,int k){
    //printf("dfs %d %d\n",x,k);
    visit[k][x]=true;
    int p=path[x].size();
    for (int i=0;i<p;i++){
        int to=path[x][i];
        if (!visit[k][to])
            dfs(to,k);
    }
}
int main()
{
    int n;
    while (scanf("%d",&n),n){
        for (int i=1;i<=n;i++){
            path[i].clear();
            for (int j=1;j<=n;j++)
                visit[i][j]=false;
        }
        int st,ed;
        while (scanf("%d",&st),st){
            while (scanf("%d",&ed),ed)
                path[st].push_back(ed);
        }
        for (int i=1;i<=n;i++){
            for (int j=0;j<path[i].size();j++)
                dfs(path[i][j],i);
            ans[i]=0;
            for (int j=1;j<=n;j++)
                ans[i]+=(!visit[i][j]);
        }
        int q,tmp;
        scanf("%d",&q);
        while (q--){
            scanf("%d",&tmp);
            printf("%d",ans[tmp]);
            for (int i=1;i<=n;i++)
                if (!visit[tmp][i])
                    printf(" %d",i);
            puts("");
        }
    }
}
