#include <iostream>
using namespace std;

int n,c[30],ans,d[1048576];
void dfs(int x,int sum,bool check)
{
    if (ans==1048575)
        return;
    if (check)
    {
        if (d[sum]>=0&&d[sum]<=x)
            return;
        d[sum]=x;
        if (sum>ans)
            ans=sum;
    }
    if (x==n)
        return;
    dfs(x+1,sum,0);
    dfs(x+1,sum^c[x],1);
}
int main()
{
    while (cin>>n)
    {
        if (n==0)
            break;
        ans=0;
        for (int i=0;i<n;i++)
            cin>>c[i];
        memset(d,-1,sizeof(d));
        d[0]=0;
        dfs(0,0,0);
        cout<<ans<<endl;
    }
    return 0;
}
