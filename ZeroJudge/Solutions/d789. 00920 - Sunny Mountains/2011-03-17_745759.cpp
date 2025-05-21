#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

struct Node {int x,y;} m[100000];
bool cmp(Node i,Node j)
{
    return i.x>j.x;
}
int main()
{
    cout.setf(ios::fixed);
    cout.precision(2);
    int cases,n;
    cin>>cases;
    while (cases-->0)
    {
        cin>>n;
        for (int i=0;i<n;i++)
            cin>>m[i].x>>m[i].y;
        stable_sort(m,m+n,cmp);
        double ans=1e-8;
        int maxh=0;
        for (int i=1;i<n;i++)
            if (m[i].y>maxh)
            {
                double x=m[i].x-m[i-1].x,y=m[i].y-m[i-1].y;
                ans+=(double)(m[i].y-maxh)*sqrt(x*x+y*y)/y;
                maxh=m[i].y;
            }
        cout<<ans<<endl;
    }
    return 0;
}
