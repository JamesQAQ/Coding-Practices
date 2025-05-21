#include <iostream>
using namespace std;

int num[5],ans[5];
bool use[5],ok;
void dfs(int x,int sum)
{
    if (x==5)
    {
        if (sum==23)
            ok=1;
        return;
    }
    dfs(x+1,sum+ans[x]);
    if (ok)
        return;
    dfs(x+1,sum-ans[x]);
    if (ok)
        return;
    dfs(x+1,sum*ans[x]);
    return;
}
void dfs_c(int x)
{
    if (x==5)
    {
        /*for (int i=0;i<5;i++)
            cout<<ans[i]<<" ";
        cout<<endl;*/
        dfs(1,ans[0]);
        return;
    }
    for (int i=0;i<5;i++)
        if (!use[i])
        {
            use[i]=1;
            ans[x]=num[i];
            dfs_c(x+1);
            if (ok)
                return;
            use[i]=0;
        }
}
int main()
{
    while (1)
    {
        bool zero=1;
        for (int i=0;i<5;i++)
        {
            cin>>num[i];
            if (num[i]!=0)
                zero=0;
        }
        if (zero)
            break;
        ok=0;
        memset(use,0,sizeof(use));
        dfs_c(0);
        if (ok)
            cout<<"Possible\n";
        else
            cout<<"Impossible\n";
    }
    return 0;
}
