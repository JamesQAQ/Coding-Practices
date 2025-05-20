#include <iostream>
using namespace std;

int cases,n,row[1001],temp;
long long sum=0,dp[1000][1000],MAX=0x7FFFFFFFFFFFFFLL;
int main()
{
    scanf("%d",&cases);
    for (int i=0;i<cases;i++)
    {
        scanf("%d",&n);
        scanf("%d",&row[0]);
        scanf("%d",&row[1]);
        for (int j=2;j<n+1;j++)
        {
            scanf("%d",&temp);
            scanf("%d",&row[j]);
        }
        for (int j=0;j<n;j++)
        {
            dp[j][j]=0;
            for (int k=j+1;k<n;k++)
                dp[j][k]=MAX;
        }
        for (int d=1;d<n;d++)
            for (int j=0;j<n-d;j++)
                for (int k=j;k<j+d;k++)
                    dp[j][j+d]=min(dp[j][j+d],dp[j][k]+dp[k+1][j+d]+row[j]*row[k+1]*row[j+d+1]);
        cout<<(dp[0][n-1]-1)/1000+1<<endl;
        sum+=dp[0][n-1];
    }
    cout<<(sum-1)/1000+1<<endl;
    return 0;
}
