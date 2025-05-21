#include <cstdio>

int min(int a,int b){
    return (a<b)?a:b;
}
int main()
{
    int cases,n,dp[200][3];
    char s[201];
    scanf("%d",&cases);
    for (int t=1;t<=cases;t++){
        scanf("%d %s",&n,s);
        if (s[0]=='.'){
            dp[0][0]=0;
            dp[0][1]=101;
            dp[0][2]=1;
        }
        else{
            dp[0][0]=101;
            dp[0][1]=0;
            dp[0][2]=1;
        }
        for (int i=1;i<n;i++){
            if (s[i]=='.'){
                dp[i][0]=dp[i-1][1];
                dp[i][1]=dp[i-1][2];
                dp[i][2]=min(dp[i-1][0]+1,min(dp[i-1][1]+1,dp[i-1][2]+1));
            }
            else{
                dp[i][0]=101;
                dp[i][1]=min(dp[i-1][1],dp[i-1][2]);
                dp[i][2]=min(dp[i-1][0]+1,min(dp[i-1][1]+1,dp[i-1][2]+1));
            }
        }
        printf("Case %d: %d\n",t,min(dp[n-1][1],dp[n-1][2]));
    }
}
