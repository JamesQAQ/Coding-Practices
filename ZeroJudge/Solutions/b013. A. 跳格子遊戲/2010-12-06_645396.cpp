#include <iostream>
#include <deque>
using namespace std;

int n;
deque <int> path[10001];
short state[10001];//2=win
void dfs(int x)
{
    int p=path[x].size();
    state[x]=1;
    for (int i=0;i<p;i++)
    {
        int y=path[x][i];
        if (state[y]==0)
            dfs(y);
        if (state[y]==1)
            state[x]=2;
    }
}
int main()
{
    string s;
    int e,a,b;
    while (cin>>n>>e)
    {
        if (n==0&&e==0)
            break;
        for (int i=1;i<=n;i++)
        {
            state[i]=0;
            path[i].clear();
        }
        for (int i=0;i<e;i++)
        {
            cin>>a>>b;
            path[a].push_back(b);
        }
        state[n]=1;
        dfs(1);
        cin>>s;
        if (s=="Moumou")
            cout<<((state[1]==2)?"Mimi":"Moumou")<<endl;
        else
            cout<<((state[1]==1)?"Mimi":"Moumou")<<endl;
    }
    return 0;
}
