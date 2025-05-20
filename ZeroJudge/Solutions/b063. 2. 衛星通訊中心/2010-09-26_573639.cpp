#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

int main()
{
    int n,a[1001][2],mini,ans;
    while (scanf("%d",&n)==1)
    {
        mini=0;
        for (int i=0;i<n;i++)
            scanf("%d %d",&a[i][0],&a[i][1]);
        for (int i=0;i<n;i++)
        {
            int sum=0;
            for (int j=0;j<n;j++)
                sum+=abs(a[i][0]-a[j][0])+abs(a[i][1]-a[j][1]);
            if (mini==0)
            {
                mini=sum;
                ans=i;
            }
            else
                if (sum<mini)
                {
                    mini=sum;
                    ans=i;
                }
        }
        printf("%d %d\n%d\n",a[ans][0],a[ans][1],mini);
    }
    return 0;
}
