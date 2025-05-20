#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int n,a[10001],time[10001];
    while (scanf("%d",&n)==1)
    {
        int x;
        a[0]=0;
        time[0]=0;
        for (int i=0;i<n;i++)
        {
            scanf("%d",&x);
            while (x>0)
            {
                a[x]=i;
                time[x]=time[i]+1;
                scanf("%d",&x);
            }
        }
        int ans=0;
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                if (i!=j)
                {
                    int k=i,l=j;
                    while (k!=l)
                    {
                        while (k>l) k=a[k];
                        while (k<l) l=a[l];
                    }
                    int sum=time[i]+time[j]-2*time[k];
                    if (sum>ans)
                        ans=sum;
                }
        printf("%d\n",ans);
    }
    return 0;
}
