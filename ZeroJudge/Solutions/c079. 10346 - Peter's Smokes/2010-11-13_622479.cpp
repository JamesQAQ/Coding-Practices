#include <iostream>
using namespace std;

int main()
{
    int n,k,ans,sum;
    while (cin>>n>>k)
    {
        ans=n;
        sum=n;
        while (n>=k)
        {
            ans+=n/k;
            n=n%k+n/k;
        }
        cout<<ans<<endl;
    }
    return 0;
}
