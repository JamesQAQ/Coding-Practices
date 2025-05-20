#include <iostream>
using namespace std;

bool through[2000];
int path[2000][2000],d[2000],ans,num,n;
string name[2000];
int search(string s)
{
    for (int i=0;i<num;i++)
        if (s==name[i])
            return i;
    name[num++]=s;
    return num-1;
}
void dfs(int x,int sum)
{
    if (d[x]==1)
    {
        if (sum>ans)
            ans=sum;
        return;
    }
    for (int i=0;i<d[x];i++)
        if (!through[path[x][i]])
        {
            through[path[x][i]]=1;
            dfs(path[x][i],sum+1);
            through[path[x][i]]=0;
        }
}
int main()
{
    string a,b;
    int cases,ata,atb;
    while (cin>>cases)
        for (int t=0;t<cases;t++)
        {
            cin>>n;
            num=0;
            ans=0;
            for (int i=0;i<n;i++)
            {
                through[i]=0;
                d[i]=0;
            }
            while (cin>>a>>b)
            {
                if (a[0]=='='&&b[0]=='=')
                    break;
                ata=search(a);
                atb=search(b);
                path[ata][d[ata]++]=atb;
                path[atb][d[atb]++]=ata;
            }
            for (int i=0;i<n;i++)
                if (d[i]==1)
                {
                    through[i]=1;
                    for (int j=0;j<d[i];j++)
                    {
                        through[path[i][j]]=1;
                        dfs(path[i][j],1);
                        through[path[i][j]]=0;
                    }
                    through[i]=0;
                }
            cout<<ans<<endl;
        }
    return 0;
}
