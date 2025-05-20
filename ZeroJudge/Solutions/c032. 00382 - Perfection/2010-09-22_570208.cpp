#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int n;
    puts("PERFECTION OUTPUT");
    while (scanf("%d",&n))
    {
        if (n==0)
        {
            puts("END OF OUTPUT");
            break;
        }
        int sum=0;
        for (int i=2;i*i<=n;i++)
        {
            if (n%i==0)
            {
                sum+=i;
                sum+=n/i;
            }
        }
        if (n!=1)
            sum++;
        printf("%5d  ",n);
        if (sum>n)
            puts("ABUNDANT");
        else if (sum<n)
            puts("DEFICIENT");
        else
            puts("PERFECT");
    }
    return 0;
}
