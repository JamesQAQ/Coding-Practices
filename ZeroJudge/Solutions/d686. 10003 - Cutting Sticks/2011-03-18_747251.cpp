#include <iostream>
using namespace std;

int main()
{
    
    int l,n,dp[52][52],d[52];
    while (cin>>l)
    {
        if (l==0)
            break;
        cin>>n;
        d[0]=0;
        d[n+1]=l;
        for (int i=1;i<=n;i++)
            cin>>d[i];
        for (int i=0;i<=n;i++)
        {
            dp[i][i+1]=0;
            for (int j=i+2;j<=n+1;j++)
                dp[i][j]=INT_MAX;
        }
        for (int k=2;k<=n+1;k++)
            for (int i=0;i+k<=n+1;i++)
                for (int j=i+1;j<i+k;j++)
                    dp[i][i+k]=min(dp[i][i+k],dp[i][j]+dp[j][i+k]+d[i+k]-d[i]);
        /*        for (int i=0;i<=n+1;i++)
        {
            for (int j=0;j<=n+1;j++)
                cout<<dp[i][j]<<" ";
            cout<<endl;
        }*/
        cout<<"The minimum cutting is "<<dp[0][n+1]<<"."<<endl;
    }
    return 0;
}
