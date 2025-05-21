#include <iostream>
using namespace std;

int boss[1000001],sum[1000001];
bool use[1000001];
int search(int x)
{
    return (x==boss[x])?x:boss[x]=search(boss[x]);
}
int main()
{
    int n,temp;
    while (scanf("%d",&n)==1)
    {
        for (int i=1;i<=n;i++)
        {
            boss[i]=i;
            use[i]=0;
            sum[i]=1;
        }
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&temp);
            int bossi=search(i),bosstemp=search(temp);
            if (bossi==bosstemp)
                continue;
            boss[bosstemp]=bossi;
            sum[bossi]+=sum[bosstemp];
            sum[bosstemp]=0;
        }
        int ans=0,anssum=0;
        for (int i=1;i<=n;i++)
        {
            int p=search(i);
            if (!use[p])
            {
                anssum++;
                ans=max(ans,sum[p]);
                use[p]=1;
            }
        }
        printf("%d %d\n",anssum,ans);
    }
    return 0;
}
