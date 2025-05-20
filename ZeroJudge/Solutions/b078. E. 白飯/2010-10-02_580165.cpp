#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int n,a[1000];
    while (scanf("%d",&n))
    {
        if (n==0)
            break;
        double adv=0;
        for (int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            adv+=a[i];
        }
        adv/=n;
        int sum=0;
        for (int i=0;i<n;i++)
            if (a[i]<adv)
                sum++;
        printf("%d\n",sum);
    }
    return 0;
}
