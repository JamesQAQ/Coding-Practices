#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int n,N,x=2;
    int num[10001]={1,1,2};
    for (int i=3;i<10001;i++)
    {
        x*=i;
        while (x%10==0)
            x/=10;
        num[i]=x%10;
        x%=100000;
    }
    while (scanf("%d",&N)==1)
        printf("%5d -> %d\n",N,num[N]);
    return 0;
}
