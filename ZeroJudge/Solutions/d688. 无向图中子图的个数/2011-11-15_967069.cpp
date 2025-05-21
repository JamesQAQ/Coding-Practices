#include <cstdio>
#include <vector>

int pow2[21];
bool dp[1048576];
std::vector <int> path[20];
int main()
{
    pow2[0]=1;
    for (int i=1;i<=20;i++)
        pow2[i]=pow2[i-1]<<1;
    int n,m,a,b;
    while (scanf("%d %d",&n,&m)){
        if (n==0&&m==0)
            break;
        for (int i=0;i<n;i++)
            path[i].clear();
        for (int i=0;i<pow2[n];i++)
            dp[i]=false;
        for (int i=0;i<n;i++)
            dp[pow2[i]]=true;
        for (int i=0;i<m;i++){
            scanf("%d %d",&a,&b);
            a--,b--;
            path[a].push_back(b);
            path[b].push_back(a);
        }
        int ans=0;
        for (int i=1;i<pow2[n];i++)
            if (dp[i]){
                ans++;
                for (int j=0;j<n;j++)
                    if ((pow2[j]&i)==0){
                        int p=path[j].size();
                        for (int k=0;k<p;k++)
                            if (pow2[path[j][k]]&i)
                                dp[i+pow2[j]]=true;
                    }
            }
        printf("%d\n",ans);
    }
    return 0;
}
