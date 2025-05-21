#include <iostream>
#include <sstream>
using namespace std;

int path[101][100],num[100],n,t;
bool ok[101][101],use[101];
void dfs(int x,int d)
{
    t++;
    use[x]=1;
    for (int i=0;i<num[x];i++)
        if (!use[path[x][i]]&&path[x][i]!=d)
            dfs(path[x][i],d);
}
int main()
{
    string s;
    int a,b;
    while (cin>>n)
    {
        if (n==0)
            break;
        for (int i=1;i<=n;i++)
        {
            num[i]=0;
            for (int j=1;j<=n;j++)
                ok[i][j]=0;
        }
        getline(cin,s);
        while (getline(cin,s))
        {
            stringstream ss(s);
            ss>>a;
            if (a==0)
                break;
            while (ss>>b)
                if (!ok[a][b])
                {
                    ok[a][b]=1;
                    ok[b][a]=1;
                    path[a][num[a]++]=b;
                    path[b][num[b]++]=a;
                }    
        }
        int ans=0;
        for (int i=1;i<=n;i++)
        {
            t=0;
            for (int j=1;j<=n;j++)
                use[j]=0;
            if (i==1)
                dfs(2,i);
            else
                dfs(1,i);
            if (t!=n-1)
                ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
