#include <iostream>
#include <algorithm>
using namespace std;

int dp[3500][3500],rain[3500],crain[3500],cnum=0,n,m,e,no[1000000]={};
int main()
{
    cin>>n>>m;
    for (int i=0;i<n;i++)
    {
        cin>>rain[i];
        if (no[rain[i]]==0)
        {
            crain[cnum++]=rain[i];
            no[rain[i]]=1;
        }
    }
    stable_sort(crain,crain+cnum);
    for (int i=0;i<cnum;i++)
        no[crain[i]]=i;
    for (int i=0;i<n;i++)
        rain[i]=no[rain[i]];
    for (int t=0;t<m;t++)
    {
        cin>>e;
        int ans=0;
        for (int i=0;i<n;i++)
            for (int j=0;j<cnum;j++)
                dp[i][j]=0;
        dp[0][rain[0]]=1;
        for (int i=1;i<n;i++)
            for (int j=0;j<cnum;j++)
            {
                dp[i][j]=max(dp[i][j],dp[i-1][j]);
                if (rain[i]>=j)
                    dp[i][rain[i]]=max(dp[i][rain[i]],dp[i-1][j]+1);
                else if (dp[i-1][j]!=0&&crain[j]-crain[rain[i]]<=e)
                    dp[i][j]=max(dp[i][j],dp[i-1][j]+1);
                ans=max(ans,dp[i][j]);
            }
        cout<<ans<<" ";
        /*for (int i=0;i<n;i++)
            cout<<rain[i]<<" ";
        cout<<endl;*/
        /*for (int i=0;i<cnum;i++)
        {
            for (int j=0;j<n;j++)
                cout<<dp[j][i]<<" ";
            cout<<endl;
        }*/
    }
    cout<<endl;
    return 0;
}
