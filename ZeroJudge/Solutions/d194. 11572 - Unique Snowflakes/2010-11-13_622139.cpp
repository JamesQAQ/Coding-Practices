#include <iostream>
using namespace std;

int n,a[1000000],from,end,ans;
int ok()
{
    for (int i=from;i<end;i++)
        if (a[i]==a[end])
            return i+1;
    return -1;
}
int main()
{
    int cases;
    while (cin>>cases)
    {
        for (int i=0;i<cases;i++)
        {
            cin>>n;
            for (int j=0;j<n;j++)
                cin>>a[j];
            from=0;
            ans=0;
            for (end=1;end<n;end++)
            {
                int p=ok();
                if (p!=-1)
                    from=p;
                if (end-from+1>ans)
                    ans=end-from+1;
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
