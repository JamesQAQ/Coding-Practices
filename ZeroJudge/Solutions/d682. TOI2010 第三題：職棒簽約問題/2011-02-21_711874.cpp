#include <iostream>
using namespace std;
struct Node {int x,y;} a[51][50];
int main()
{
    int dp[51][10001],m,n,p;
    while (cin>>m>>n>>p)
    {
        for (int i=1;i<=n;i++)
            for (int j=0;j<p;j++)
                cin>>a[i][j].x>>a[i][j].y;
        for (int i=0;i<=n;i++)
            dp[i][0]=0;
        for (int i=0;i<=m;i++)
            dp[0][i]=0;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
            {
                dp[i][j]=0;
                for (int k=0;k<p;k++)
                    if (a[i][k].x<=j&&dp[i-1][j-a[i][k].x]+a[i][k].y>dp[i][j])
                        dp[i][j]=dp[i-1][j-a[i][k].x]+a[i][k].y;
                dp[i][j]=max(dp[i][j],dp[i-1][j]);
            }
        int ans=0;
        for (int i=0;i<=m;i++)
            ans=max(ans,dp[n][i]);
        cout<<ans<<endl;
    }
    return 0;
}
