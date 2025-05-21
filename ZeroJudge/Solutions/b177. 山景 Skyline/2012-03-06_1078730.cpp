#include <cstdio>

int dp[1501][1501],sum[1501][1501]={},mod=1000000000;
int check(int p){
    if (p>mod)
        p-=mod;
    else if (p<0)
        p+=mod;
    return p;
}
int main()
{
    int n;
    scanf("%d",&n);
    n/=2;
    dp[1][1]=sum[1][1]=1;
    for (int i=2;i<=n;i++){
        dp[i][1]=1;
        sum[i][1]=check(dp[i][1]+sum[i-1][1]);
        check(sum[i][1]);
        for (int j=2;j<i;j++){
            dp[i][j]=check(dp[i-1][j-1]+check(sum[i-1][j]-sum[i-j-1][j]));
            sum[i][j]=check(dp[i][j]+sum[i-1][j]);
        }
        dp[i][i]=sum[i][i]=1;
    }
    int ans=0;
    for (int i=1;i<=n;i++)
        ans=check(ans+dp[n][i]);
    printf((n>22)?"%09d\n":"%d\n",ans);
}
