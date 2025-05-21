#include <iostream>
using namespace std;

int main()
{
    int t,n,maxx,sum;
    cin>>t;
    bool use[46];
    while (t-->0)
        while (cin>>n)
        {
            maxx=2;
            sum=2;
            use[2]=1;
            while (sum<n||sum-1==n)
            {
                sum+=++maxx;
                use[maxx]=1;
            }
            for (int i=maxx-1;i>=2;i--)
            {
                if (sum-i>=n)
                {
                    sum-=i;
                    use[i]=0;
                }
                if (sum==n)
                    break;
            }
            for (int i=2;i<=maxx;i++)
                if (use[i])
                    cout<<i<<" ";
            cout<<endl;
        }
    return 0;
}
