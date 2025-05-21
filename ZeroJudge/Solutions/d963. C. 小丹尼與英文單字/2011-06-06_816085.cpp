#include <cstdio>
#include <string.h>

char a[5001],b[5001];
int dp[5001][5001];
int max(int x,int y){
    return (x<y)?y:x;
}
int main()
{
    int cases;
    scanf("%d",&cases);
    while (cases--){
        scanf("%s",a);
        int len=strlen(a);
        for (int i=0;i<len;i++)
            b[i]=a[len-i-1];
        for (int i=0;i<len;i++)
            dp[0][i]=dp[i][0]=0;
        for (int i=1;i<=len;i++)
            for (int j=1;j<=len;j++){
                if (a[i-1]==b[j-1])
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        printf("%d\n",dp[len][len]);
    }
    return 0;
}
