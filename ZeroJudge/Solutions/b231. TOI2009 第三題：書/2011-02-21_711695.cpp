#include <iostream>
#include <algorithm>
using namespace std;

struct Node {int t,d;} a[1000];
bool cmp(Node i,Node j)
{
    return i.d>j.d;
}
int main()
{
    int n,ans,sum;
    while (cin>>n)
    {
        for (int i=0;i<n;i++)
            cin>>a[i].t>>a[i].d;
        stable_sort(a,a+n,cmp);
        sum=ans=0;
        for (int i=0;i<n;i++)
        {
            sum+=a[i].t;
            if (sum+a[i].d>ans)
                ans=sum+a[i].d;
        }
        cout<<ans<<endl;
    }
    return 0;
}
