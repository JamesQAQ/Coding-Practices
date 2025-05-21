#include <iostream>
#include <deque>
using namespace std;

deque <int> bigto[10001];
int n,money[10001];
bool use[10001]={},insearch[10001]={},wrong;
void dfs(int x)
{
    if (use[x])
        return;
    if (insearch[x])
    {
        wrong=1;
        return;
    }
    insearch[x]=1;
    for (int i=0;i<bigto[x].size();i++)
    {
        dfs(bigto[x][i]);
        if (wrong)
            return;
        money[x]=max(money[x],money[bigto[x][i]]+1);
    }
    insearch[x]=0;
    use[x]=1;
}
int main()
{
    int m,a,b,ans;
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        bigto[i].clear();
        money[i]=100;
    }
    for (int i=0;i<m;i++)
    {
        cin>>a>>b;
        bigto[a].push_back(b);
    }
    int start=1;
    for (int i=2;i<=n;i++)
        if (bigto[i].size()<bigto[start].size())
            start=i;
    use[start]=1;
    ans=0;
    wrong=0;
    for (int i=1;i<=n;i++)
    {
        dfs(i);
        ans+=money[i];
    }
    if (wrong)
        cout<<"Poor Xed"<<endl;
    else
        cout<<ans<<endl;
    //system("pause");
    return 0;
}
