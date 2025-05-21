#include <iostream>
using namespace std;

int main()
{
    int n,t,w[2000],lis[2000],lds[2000],ans;
    cin>>t;
    while (t-->0)
    {
        cin>>n;
        for (int i=n-1;i>=0;i--)
        {
            cin>>w[i];
            lis[i]=lds[i]=1;
        }
        if (n==1)
        {
            puts("1");
            continue;
        }
        ans=0;
        for (int i=1;i<n;i++)
        {
            for (int j=0;j<i;j++)
            {
                if (w[j]<w[i]&&lis[j]+1>lis[i])
                    lis[i]=lis[j]+1;
                if (w[j]>w[i]&&lds[j]+1>lds[i])
                    lds[i]=lds[j]+1;
            }
            if (lis[i]+lds[i]-1>ans)
                ans=lis[i]+lds[i]-1;
        }
        cout<<ans<<endl;
    }
    return 0;
}
