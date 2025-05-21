#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

int main()
{
    int a[200],n,i=0;
    while (scanf("%d",&n))
    {
        if (n==0)
            break;
        int sum=0;
        i++;
        printf("Set #%d\n",i);
        for (int j=0;j<n;j++)
        {
            scanf("%d",&a[j]);
            sum+=a[j];
        }
        int ans=0;
        sum/=n;
        for (int j=0;j<n;j++)
            ans+=abs(sum-a[j]);
        printf("The minimum number of moves is %d.\n",ans/2);
    }
    return 0;
}
