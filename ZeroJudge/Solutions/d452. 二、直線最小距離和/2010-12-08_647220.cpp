#include <iostream>
using namespace std;

int main()
{
    int m[1000],n,t;
    while (cin>>t)
        while (t-->0)
        {
            cin>>n;
            for (int i=0;i<n;i++)
                cin>>m[i];
            stable_sort(m,m+n);
            int ans=0;
            for (int i=0;i<n/2;i++)
                ans+=m[n-i-1]-m[i];
            cout<<ans<<endl;
        }
    return 0;
}
