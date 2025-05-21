#include <cstdio>

int a[10000],dp[2][10000],ans[10000];
int max(int a,int b){
    return (a>b)?a:b;
}
int main()
{
    int n,m;
    while (scanf("%d %d",&n,&m)==2){
        for (int i=0;i<n;i++){
            scanf("%d",&a[i]);
            if (i==0)
                ans[0]=dp[0][0]=a[0];
            else{
                if (dp[0][i-1]>0)
                    dp[0][i]=dp[0][i-1]+a[i];
                else
                    dp[0][i]=a[i];
                ans[i]=max(dp[0][i],ans[i-1]);
            }
        }
        dp[1][1]=dp[0][0]+a[1];
        ans[1]=dp[1][1];
        for (int i=0;i<n;i++)
            dp[0][i]=ans[i];
        for (int i=2;i<n;i++){
            dp[1][i]=max(dp[0][i-1],dp[1][i-1])+a[i];
            ans[i]=max(dp[1][i],ans[i-1]);
        }
        printf("%d\n",ans[n-1]);
    }
}
