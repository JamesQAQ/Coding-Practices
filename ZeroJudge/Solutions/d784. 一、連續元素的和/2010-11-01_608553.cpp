#include <iostream>
using namespace std;

int main()
{
    int t,n,a[100],sum,ans;
    while (cin>>t)
    {
        for (int k=0;k<t;k++)
        {
            cin>>n;
            for (int i=0;i<n;i++)
                cin>>a[i];
            sum=0;
            ans=-1000000;
            for (int i=0;i<n;i++)
            {
                if (sum<0)
                    sum=a[i];
                else
                    sum+=a[i];
                if (sum>ans)
                    ans=sum;
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
