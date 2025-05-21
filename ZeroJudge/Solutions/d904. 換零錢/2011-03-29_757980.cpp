#include <iostream>
using namespace std;

int main()
{
    int C,n,c[10],dp[10001];
    while (scanf("%d %d",&C,&n)==2){
        for (int i=0;i<n;i++)
            scanf("%d",&c[i]);
        dp[0]=0;
        for (int i=1;i<=C;i++){
            dp[i]=INT_MAX;
            for (int j=0;j<n;j++)
                if (i-c[j]>=0)
                    dp[i]=min(dp[i],dp[i-c[j]]+1);
        }
        printf("%d\n",dp[C]);
    }
    return 0;
}
