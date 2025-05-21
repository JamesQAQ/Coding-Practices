#include <cstdio>
#include <vector>

std::vector <int> path[1001];
bool v[1001],out[1001];
int match[1001];
bool dfs(int x){
    int p=path[x].size();
    for (int i=0;i<p;i++){
        int to=path[x][i];
        if (!v[to]){
            v[to]=true;
            if (match[to]==0||dfs(match[to])){
                match[to]=x;
                out[x]=true;
                return true;
            }
        }
    }
    return false;
}
int main()
{
    int n,m,a,b;
    while (scanf("%d %d",&n,&m)){
        if (n==0&&m==0)
            break;
        for (int i=1;i<=n;i++)
            path[i].clear(),match[i]=0,out[i]=false;
        for (int i=0;i<m;i++){
            scanf("%d %d",&a,&b);
            path[a].push_back(b);
        }
        int ans=0;
        for (int i=1;i<=n;i++)
            if (!out[i]){
                for (int j=1;j<=n;j++)
                    v[j]=false;
                if (dfs(i))
                    ans++;
            }
        printf("%d\n",n-ans);
    }
    return 0;
}
