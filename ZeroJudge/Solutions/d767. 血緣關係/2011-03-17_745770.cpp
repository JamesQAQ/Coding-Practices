#include <iostream>
using namespace std;

int main()
{
    int n,m,a[30001],time[30001],b,c;
    while (scanf("%d",&n)==1)
    {
        scanf("%d",&m);
        int x;
        a[1]=1;
        time[1]=0;
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&x);
            while (x!=0)
            {
                a[x]=i;
                time[x]=time[i]+1;
                scanf("%d",&x);
            }
        }
        for (int i=0;i<m;i++)
        {
            scanf("%d %d",&b,&c);
            int k=b,l=c;
            while (k!=l)
            {
                while (k>l) k=a[k];
                while (k<l) l=a[l];
            }
            printf("%d %d\n",k,time[b]+time[c]-2*time[k]);
        }
    }
    return 0;
}
