#include <iostream>
#include <stdio.h>
using namespace std;

bool prime[1000001]={0};
void prime_test();
int main()
{
    int n;
    prime_test();
    while (scanf("%d",&n))
    {
        if (n==0)
            break;
        if (prime[n])
            puts("0");
        else
            puts("1");
    }
    //system ("pause");
    return 0;
}

void prime_test()
{
    prime[2]=1;
    for (int i=3;i<1000000;i+=2)
        prime[i]=1;
    for (int i=3;i*i<1000000;i+=2)
    {
        if (prime[i]==1)
            for (int j=i+i+i;j<1000000;j+=2*i)
                prime[j]=0;
    }
}
