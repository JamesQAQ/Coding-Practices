#include <cstdio>
#include <algorithm>

int main()
{
    int cases,dp[20],n;
    while (scanf("%d",&cases)==1)
        while (cases--){
            scanf("%d",&n);
            for (int i=0;i<4;i++)
                scanf("%d",&dp[i]);
            for (int i=4;i<n;i++)
                dp[i]=dp[i-4]+dp[i-1];
            std::stable_sort(dp,dp+n);
            printf("%d\n",dp[n/2]);
        }
    return 0;
}
