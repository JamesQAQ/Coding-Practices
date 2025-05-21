#include <iostream>
using namespace std;

bool ans[16];
int n,m;
void dfs(int x,int sum)
{
    if (x==n)
    {
        for (int i=0;i<n;i++)
            cout<<ans[i];
        cout<<endl;
        return;
    }
    if (n-x>m-sum)
    {
        ans[x]=0;
        dfs(x+1,sum);
    }
    if (sum<m)
    {
        ans[x]=1;
        dfs(x+1,sum+1);
    }
}
int main()
{
    int cases;
    cin>>cases;
    while (cases-->0)
    {
        cin>>n>>m;
        dfs(0,0);
        cout<<endl;
    }
    return 0;
}
