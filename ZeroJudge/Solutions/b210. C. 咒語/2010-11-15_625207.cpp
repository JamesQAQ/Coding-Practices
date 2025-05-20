#include <iostream>
#include <deque>
using namespace std;

deque <int> y[10000],z[10000];
int ans[10000],n,m;
int main()
{
    int a,b,c;
    while (cin>>n>>m)
    {
        if (n==0&&m==0)
            break;
        for (int i=0;i<n;i++)
        {
            y[i].clear();
            z[i].clear();
        }
        for (int i=0;i<m;i++)
        {
            cin>>a>>b>>c;
            int aa=min(a,b),bb=max(a,b);
            y[bb].push_back(aa);
            z[bb].push_back(c);
        }
        ans[0]=0;
        for (int i=1;i<n;i++)
        {
            int x=ans[i-1];
            for (int j=0;j<y[i].size();j++)
            {
                int xx=ans[y[i][j]]+z[i][j];
                if (xx>x)
                    x=xx;
            }
            ans[i]=x;
        }
        cout<<ans[n-1]<<endl;
    }
    return 0;
}
