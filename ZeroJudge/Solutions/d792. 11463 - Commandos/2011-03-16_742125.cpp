#include <iostream>
using namespace std;

int main()
{
    int cases,n,a,b,path[100][100],m,s,d;
    cin>>cases;
    for (int t=0;t<cases;t++)
    {
        cin>>n>>m;
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                path[i][j]=-1;
        for (int i=0;i<n;i++)
            path[i][i]=0;
        for (int i=0;i<m;i++)
        {
            cin>>a>>b;
            path[a][b]=path[b][a]=1;
        }
        for (int k=0;k<n;k++)
            for (int i=0;i<n;i++)
                for (int j=0;j<n;j++)
                    if (path[i][k]!=-1&&path[k][j]!=-1)
                        if (path[i][j]==-1||path[i][j]>path[i][k]+path[k][j])
                            path[i][j]=path[i][k]+path[k][j];
        cin>>s>>d;
        int ans=0;
        for (int i=0;i<n;i++)
            ans=max(ans,path[s][i]+path[i][d]);
        cout<<"Case "<<t+1<<": "<<ans<<endl;
    }
    return 0;
}
