#include <cstdio>
#include <vector>

int st,ed;
std::vector <int> path[801];
bool use[801];
bool dfs(int x){
    use[x]=true;
    if (x==ed)
        return true;
    int p=path[x].size();
    for (int i=0;i<p;i++){
        int to=path[x][i];
        if ((!use[to])&&dfs(to))
            return true;
    }
    return false;
}
int main()
{
    int n,m,a,b;
    while (scanf("%d %d",&n,&m)==2){
        for (int i=1;i<=n;i++)
            path[i].clear(),use[i]=false;
        for (int i=0;i<m;i++)
            scanf("%d %d",&a,&b),path[a].push_back(b);
        scanf("%d %d",&st,&ed);
        puts((dfs(st))?"Yes!!!":"No!!!");
    }
    return 0;
}
