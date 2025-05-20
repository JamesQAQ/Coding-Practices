#include <iostream>
#include <algorithm>
using namespace std;

int n,a[10000][2],t[10000],ans,timee;
bool cmp(int i,int j)
{
    return a[i][1]>a[j][1];
}
int main()
{
    while (cin>>n)
    {
        if (n==0)
            break;
        timee=0;
        ans=0;
        for (int i=0;i<n;i++)
        {
            t[i]=i;
            cin>>a[i][0]>>a[i][1];
        }
        stable_sort(t,t+n,cmp);
        for (int i=0;i<n;i++)
        {
            timee+=a[t[i]][0];
            if (timee+a[t[i]][1]>ans)
                ans=timee+a[t[i]][1];
        }
        cout<<ans<<endl;
    }
    return 0;
}
