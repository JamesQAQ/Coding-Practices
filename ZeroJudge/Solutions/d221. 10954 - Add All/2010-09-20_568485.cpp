#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int n,amount,num[100001]={};
    long long int big[4999],cost;
    while (scanf("%d",&n)==1)
    {
        if (n==0)
            break;
        int m;
        amount=0;
        cost=0;
        long long int a=0,b=0;
        for (int i=0;i<n;i++)
        {
            scanf("%d",&m);
            num[m]++;
        }
        for (int i=1;i<100001;i++)
            while (num[i]>0)
            {
                if (a==0)
                {
                    a=i;
                    num[i]--;
                }
                else if (b==0)
                {
                    b=i;
                    num[i]--;
                }
                if ((a>0)&&(b>0))
                {
                    long long int sum=a+b;
                    cost+=sum;
                    if (sum<100001)
                        num[sum]++;
                    else
                    {
                        big[amount]=sum;
                        amount++;
                    }
                    a=0;
                    b=0;
                }
            }
        int j=0;
        while (j<amount)
        {
            if (a==0)
                a=big[j++];
            else if (b==0)
                b=big[j++];
            if ((a>0)&&(b>0))
            {
                long long int sum=a+b;
                cost+=sum;
                big[amount]=sum;
                amount++;
                a=0;
                b=0;
            }
        }
        printf("%lld\n",cost);
    }
    return 0;
}
