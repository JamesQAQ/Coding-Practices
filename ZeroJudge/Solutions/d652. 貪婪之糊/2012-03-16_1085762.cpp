#include <cstdio>

int main()
{
    int n,a[50],dp[50][50];
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for (int i=0;i<n-1;i++)
        dp[i][i+1]=0;
    for (int k=2;k<n;k++)
        for (int i=0;i+k<n;i++){
            int tmp=2147483647;
            for (int j=i+1;j<i+k;j++){
                int v=dp[i][j]+dp[j][i+k]+a[i]*a[j]*a[i+k];
                if (v<tmp) tmp=v;
            }
            dp[i][i+k]=tmp;
        }
    printf("%d\n",dp[0][n-1]);
}
