#include <iostream>
using namespace std;

int map[2001][2001],n,m,a,b,s;
int main()
{
    while (cin>>n>>m)
    {
        if (n==0&&m==0)
            break;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                map[i][j]=0;
        for (int i=0;i<m;i++)
        {
            cin>>a>>b;
            cin>>s;
            if (s>map[a][b])
            map[b][a]=map[a][b]=s;
        }
        for (int k=1;k<=n;k++)
            for (int i=1;i<=n;i++)
                for (int j=1;j<=n;j++)
                    if (i!=j&&map[i][k]&&map[k][j])
                        map[i][j]=max(map[i][j],min(map[i][k],map[k][j]));
        cin>>a>>b;
        cout<<map[a][b]<<endl;
    }
    return 0;
}
