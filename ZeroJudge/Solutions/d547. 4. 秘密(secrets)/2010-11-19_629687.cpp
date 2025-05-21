#include <iostream>
#include <cmath>
using namespace std;

bool test(bool p[],int aa[],int m)
{
    int a[10000];
    for (int j=0;j<m+1;j++)
        a[j]=aa[j];
    for (int j=m;j>0;j--)
    {
        if (a[j]>=a[j-1]&&!p[j-1])
            return 0;
        else if (a[j]<a[j-1]&&p[j-1])
            return 0;
        a[j-1]=abs(aa[j]-aa[j-1]);
    }
    return 1;
}
int main()
{
    int n,m,a[10000],ans[10000];
    bool findok,pass[10000];
    while (cin>>n>>m)
    {
        findok=0;
        for (int i=0;i<m;i++)
            cin>>pass[i];
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<m+1;j++)
                cin>>a[j];
            if (findok)
                continue;
            else if (test(pass,a,m))
            {
                findok=1;
                for (int j=0;j<m+1;j++)
                    ans[j]=a[j];
            }
        }
        for (int i=0;i<m+1;i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
