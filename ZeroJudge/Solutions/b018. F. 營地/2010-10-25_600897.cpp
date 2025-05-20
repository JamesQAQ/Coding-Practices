#include <iostream>
using namespace std;

int main()
{
    int a[5000],ans,l,w,temp;
    while (scanf("%d",&l))
    {
        scanf("%d",&w);
        if (l==0&&w==0)
            break;
        for (int i=0;i<w;i++)
            a[i]=0;
        ans=0;
        for (int i=0;i<l;i++)
        {
            int maxx=0;
            for (int j=0;j<w;j++)
            {
                scanf("%d",&temp);
                if (temp==2)
                    a[j]=0;
                else
                    a[j]++;
                if (a[j]>maxx)
                    maxx=a[j];
            }
            for (int j=ans+1;j<=maxx;j++)
            {
                int sum=0;
                for (int k=0;k<w;k++)
                {
                    if (sum+w-k<j)
                        break;
                    if (a[k]<j)
                        sum=0;
                    else
                        sum++;
                    if (sum==j)
                        break;
                }
                if (sum!=j)
                    break;
                ans=j;
            }
        }
        printf("%d\n",ans*ans);
    }
    return 0;
}
