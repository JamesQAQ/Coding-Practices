#include <cstdio>

int main()
{
    long long dp[91][16];
    int n,m;
    while (scanf("%d %d",&n,&m)==2){
        for (int i=1;i<=n;i++)
            dp[0][i]=-1;
        dp[0][0]=1;
        for (int i=1;i<=m;i++)
            for (int j=0;j<=n;j++)
                dp[i][j]=0;
        for (int i=0;i<m;i++)
            for (int j=0;j<=n;j++)
                if (dp[i][j]!=-1){
                    if (j!=n)
                        dp[i+1][j+1]+=dp[i][j];
                    dp[i+1][0]+=dp[i][j];
                }
        long long ans=0;
        for (int i=0;i<=n;i++)
            ans+=dp[m][i];
        printf("%lld\n",ans);
    }
}
