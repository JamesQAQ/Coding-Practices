#include <cstdio>

int main()
{
    int dp[4][20]={};
    for (int i=1;i<=3;i++){
        dp[i][0]=1;
        for (int j=1;j<20;j++){
            dp[i][j]+=dp[i][j-1];
            if (i>=2&&j>=2)
                dp[i][j]+=dp[i][j-2];
            if (i>=3&&j>=3)
                dp[i][j]+=dp[i][j-3];
        }
    }
    int n,m;
    while (scanf("%d %d",&n,&m)==2)
        printf("%d\n",dp[n][-m]);
}
