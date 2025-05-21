#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

char dp[101][101][101]={},sa[101],sb[101],sc[101];
int main()
{
    int la,lb,lc;
    scanf("%s %s %s",sa,sb,sc);
    la=strlen(sa);
    lb=strlen(sb);
    lc=strlen(sc);
    for (int i=1;i<=la;i++)
        for (int j=1;j<=lb;j++)
            for (int k=1;k<=lc;k++){
                if (sa[i-1]==sb[j-1]&&sb[j-1]==sc[k-1])
                    dp[i][j][k]=dp[i-1][j-1][k-1]+1;
                else
                    dp[i][j][k]=max(dp[i-1][j][k],max(dp[i][j-1][k],dp[i][j][k-1]));
            }
    printf("%d\n",dp[la][lb][lc]);
    return 0;
}
