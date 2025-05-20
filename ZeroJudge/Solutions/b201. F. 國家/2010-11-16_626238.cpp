#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

deque <int> path[100001],go;
int nation[100001],num,n,m,sum;
bool use[100001],use2[100001],come[100001];
void cdfs(int g,int x)
{
    int pnum=path[x].size(),p;
    for (int i=0;i<pnum;i++)
    {
        p=path[x][i];
        if (!use2[p])
        {
            use2[p]=1;
            cdfs(g,p);
        }
        if (come[p]||p==g)
            come[x]=1;
    }
    return;
}
void dfs(int x)
{
    int pnum=path[x].size(),p;
    for (int i=0;i<pnum;i++)
    {
        p=path[x][i];
        if (!use[p])
        {
            use[p]=1;
            go.push_back(p);
            dfs(p);
        }
    }
    return;
}
int main()
{
    int a,b,sum,pnum,p;
    while (scanf("%d",&n)!=EOF)
    {
        scanf("%d",&m);
        for (int i=1;i<=n;i++)
        {
            path[i].clear();
            use[i]=0;
            use2[i]=0;
        }
        for (int i=0;i<m;i++)
        {
            scanf("%d",&a);
            scanf("%d",&b);
            path[a].push_back(b);
        }
        num=0;
        for (int i=1;i<=n;i++)
            if (!use[i])
            {
                go.clear();
                use[i]=1;
                dfs(i);
                sum=go.size();
                pnum=sum;
                for (int j=0;j<pnum;j++)
                {
                    p=go[j];
                    if (!use2[p])
                    {
                        use2[p]=1;
                        cdfs(i,p);
                    }
                    if (!come[p])
                    {
                        sum--;
                        use[p]=0;
                        use2[p]=0;
                    }
                    come[p]=0;
                }
                nation[num++]=sum+1;
            }
        stable_sort(nation,nation+num);
        for (int i=0;i<num;i++)
            printf("%d ",nation[i]);
        printf("\n");
    }
    return 0;
}
