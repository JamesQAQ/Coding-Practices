#include <iostream>
#include <algorithm>
using namespace std;

int n,a[100000];
int main()
{
    int t,maxx,ans;
    while (cin>>t)
        while (t-->0)
        {
            cin>>n;
            for (int i=0;i<n;i++)
                cin>>a[i];
            stable_sort(a,a+n);
            maxx=0;
            for (int i=0;i<n-1;i++)
                if (a[i+1]-a[i]>maxx)
                {
                    maxx=a[i+1]-a[i];
                    ans=i;
                }
            cout<<ans+1<<endl;
        }
    return 0;
}
