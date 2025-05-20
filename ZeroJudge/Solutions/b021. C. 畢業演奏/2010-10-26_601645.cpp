#include <iostream>
using namespace std;

int n,at,from,end,p,ans;
short dp[10000000],now[10000000];
int main()
{
    while (cin>>n)
    {
        if (n==0)
            break;
        dp[0]=0;
        at=0;
        ans=0;
        for (int i=0;i<n;i++)
        {
            cin>>from>>end>>p;
            if (at<end)
            {
                for (int j=at+1;j<=end;j++)
                    dp[j]=ans;
                at=end;
            }
            for (int j=from+p-1;j<=end;j++)
            {
                if (dp[j-p]+1>dp[j])
                {
                    now[j]=dp[j-p]+1;
                    if (now[j]>ans)
                        ans=now[j];
                }
                else
                    now[j]=dp[j];
            }
            for (int j=from+p-1;j<=end;j++)
                dp[j]=now[j];
        }
        cout<<ans<<endl;
    }
    return 0;
}
