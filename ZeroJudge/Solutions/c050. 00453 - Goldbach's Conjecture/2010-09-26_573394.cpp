#include <iostream>
#include <stdio.h>
using namespace std;

bool prime[1000001]={};
int main()
{
    for (int i=3;i<1000001;i+=2)
        prime[i]=1;
    for (int i=3;i*i<1000001;i+=2)
        if (prime[i])
            for (int j=i*3;j<1000001;j+=2*i)
                prime[j]=0;
    int n;
    while (scanf("%d",&n))
    {
        if (n==0)
            break;
        int k;
        for (k=3;k<=n/2;k+=2)
            if (prime[k])
                if (prime[n-k])
                    break;
        if (k==n/2+2)
            puts("Goldbach's conjecture is wrong.");
        else
            printf("%d = %d + %d\n",n,k,n-k);
    }
    return 0;
}
