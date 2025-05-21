#include <cstdio>

int max(int a,int b){
    return (a>b)?a:b;
}
int main()
{
    int t=0,n,m,a[101],b[101],dp[101][101];
    while (scanf("%d %d",&n,&m),n+m){
        t++;
        for (int i=0;i<n;i++)
            scanf("%d",&a[i]);
        for (int i=0;i<m;i++)
            scanf("%d",&b[i]);
        for (int i=0;i<=n;i++)
            dp[i][0]=0;
        for (int i=0;i<=m;i++)
            dp[0][i]=0;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++){
                if (a[i-1]==b[j-1])
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        if (t>1)
            puts("");
        printf("Twin Towers #%d\nNumber of Tiles : %d\n",t,dp[n][m]);
    }
}
