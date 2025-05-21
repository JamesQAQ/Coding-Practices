#include <cstdio>

int main()
{
    int dp[31][30]={},n,m;
    scanf("%d %d",&n,&m);
    dp[0][0]=1;
    for (int i=0;i<m;i++)
        for (int j=0;j<n;j++)
            if (dp[i][j]){
                int v=j+1;
                if (v>=n) v=0;
                dp[i+1][v]+=dp[i][j];
                v=j-1;
                if (v<0) v=n-1;
                dp[i+1][v]+=dp[i][j];
            }
    printf("%d\n",dp[m][0]);
}
