#include <iostream>
using namespace std;

char map[256][256],num[256];
bool use[256];
int n,ans;
bool ok(int x)
{
    for (int i=0;i<num[x];i++)
        if (use[map[x][i]])
            return 0;
    return 1;
}
void dfs(int x,int sum)
{
    if (x==n+1||(n-x+1)/2+sum+2<=ans)
    {
        if (sum>ans)
            ans=sum;
        return;
    }
    if (!num[x])
    {
        dfs(x+1,sum+1);
        return;
    }
    if (ok(x))
    {
        use[x]=1;
        dfs(x+1,sum+1);
        use[x]=0;
    }
    dfs(x+1,sum);
}
int main()
{
    int a,b;
    while (cin>>n)
    {
        ans=0;
        for (int i=1;i<=n;i++)
        {
            num[i]=0;
            use[i]=0;
        }
        while (cin>>a)
        {
            if (a==0)
                break;
            cin>>b;
            map[a][num[a]++]=b;
            map[b][num[b]++]=a;
        }
        dfs(1,0);
        cout<<ans<<endl;
    }
    return 0;
}
