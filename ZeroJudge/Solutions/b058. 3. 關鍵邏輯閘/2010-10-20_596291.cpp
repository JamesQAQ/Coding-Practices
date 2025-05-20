#include <iostream>
using namespace std;

int former[10000][500],latter[10000][500],numf[10000],numl[10000],maxtime[10000],cnum[10000],n,_time[10000],num,end[10000],c[10000][500];
bool use[10000],aans[10000];
void dfs(int x)
{
    use[x]=0;
    if (numf[x]==0)
    {
        maxtime[x]=_time[x];
        cnum[x]=1;
        c[x][0]=x;
        return;
    }
    int at;
    for (int i=0;i<numf[x];i++)
    {
        int j=former[x][i];
        if (use[j])
            dfs(j);
        if (maxtime[x]<maxtime[j]+_time[x])
        {
            maxtime[x]=maxtime[j]+_time[x];
            at=j;
        }
    }
    cnum[x]=cnum[at]+1;
    for (int i=0;i<cnum[at];i++)
        c[x][i]=c[at][i];
    c[x][cnum[at]]=x;
}
int main()
{
    int m;
    while (scanf("%d",&n)!=EOF)
    {
        int maxx=0,ans=0;
        for (int i=0;i<n;i++)
        {
            numf[i]=0;
            numl[i]=0;
            use[i]=1;
            maxtime[i]=0;
            aans[i]=0;
        }
        cin>>m;
        for (int i=0;i<n;i++)
            scanf("%d",&_time[i]);
        int a,b;
        for (int i=0;i<m;i++)
        {
            scanf("%d",&a);
            scanf("%d",&b);
            a--;
            b--;
            latter[a][numl[a]++]=b;
            former[b][numf[b]++]=a;
        }
        num=0;
        for (int i=0;i<n;i++)
            if (numl[i]==0)
                end[num++]=i;
        for (int i=0;i<num;i++)
        {
            dfs(end[i]);
            if (maxx<maxtime[end[i]])
                maxx=maxtime[end[i]];
        }
        for (int i=0;i<num;i++)
            if (maxtime[end[i]]==maxx)
                for (int j=0;j<cnum[end[i]];j++)
                    aans[c[end[i]][j]]=1;
        for (int i=0;i<n;i++)
            if (aans[i])
                ans++;
        printf("%d\n",ans);
    }
    return 0;
}
