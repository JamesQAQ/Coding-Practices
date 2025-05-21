#include <iostream>
#include <deque>
using namespace std;
#define MAX 100000

int up[MAX],n;
deque <int> path[MAX];
bool use[MAX];
bool dfs(int x)
{
    use[x]=1;
    for (int i=0;i<path[x].size();i++)
        if (use[path[x][i]]||!dfs(path[x][i]))
            return 0;
    return 1;
}
bool test()
{
    if (n==0)
        return 1;
    int at=0;
    for (int i=1;i<=n;i++)
    {
        if (up[i]>1)
            return 0;
        if (up[i]==0&&path[i].size()!=0)
        {
            if (at!=0)
                return 0;
            at=i;
        }
    }
    if (at==0||!dfs(at))
        return 0;
    for (int i=1;i<=n;i++)
         if (!(up[i]==0&&path[i].size()==0))
            if (!use[i])
                return 0;
    return 1;
}
int main()
{
    int a,b,t=0;
    n=0;
    while (cin>>a>>b)
    {
        if (a<0&&b<0)
            break;
        if (a==0&&b==0)
        {
            cout<<"Case "<<++t<<" is "<<((test())?"":"not ")<<"a tree.\n";
            n=0;
        }
        else
        {
            for (int i=n+1;i<=max(a,b);i++)
            {
                path[i].clear();
                use[i]=0;
                up[i]=0;
            }
            n=max(n,max(a,b));
            up[b]++;
            path[a].push_back(b);
        }
    }
    return 0;
}
