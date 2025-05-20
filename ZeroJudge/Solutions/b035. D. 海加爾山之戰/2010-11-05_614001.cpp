#include <iostream>
using namespace std;

int main()
{
    int n,ans,temp;
    while (cin>>n)
    {
        if (n==0)
            break;
        ans=0;
        for (int i=0;i<n;i++)
        {
            cin>>temp;
            ans+=temp*temp;
        }
        cout<<ans<<endl;
    }
    return 0;
}
