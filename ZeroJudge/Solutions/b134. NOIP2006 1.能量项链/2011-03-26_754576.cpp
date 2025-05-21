#include <iostream>
#include <deque>
using namespace std;
deque <int> w;
int dp[100][100];
int main()
{
    int n,temp;
    w.clear();
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        scanf("%d",&temp);
        w.push_back(temp);
    }
    w.push_back(w[0]);
    int ans=0;
    for (int d=0;d<n;d++)
    {
        for (int i=0;i<n;i++)
            dp[i][i]=0;
        for (int k=1;k<n;k++)
            for (int i=0;i+k<n;i++)
            {
                dp[i][i+k]=0;
                for (int j=i;j<i+k;j++)
                    dp[i][i+k]=max(dp[i][i+k],dp[i][j]+dp[j+1][i+k]+w[i]*w[j+1]*w[i+k+1]);
            }
        ans=max(ans,dp[0][n-1]);
        w.pop_front();
        w.push_back(w[0]);
    }
    printf("%d\n",ans);
    return 0;
}
