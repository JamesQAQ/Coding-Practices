#include <cstdio>
#include <vector>

std::vector <int> path[20001];
int sum[20001];
int dfs(int x,int f){
    sum[x]=1;
    int p=path[x].size();
    for (int i=0;i<p;i++){
        int to=path[x][i];
        if (f!=to)
            sum[x]+=dfs(to,x);
    }
    return sum[x];
}
int main()
{
    int n,a,b;
    scanf("%d",&n);
    for (int i=0;i<n-1;i++)
        scanf("%d %d",&a,&b),path[a].push_back(b),path[b].push_back(a);
    dfs(1,0);
    for (int i=1;i<=n;i++)
        printf("%5d-%5d\n",i,sum[i]);
}
