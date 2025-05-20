#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

int main()
{
    int k;
    while (scanf("%d",&k)!=EOF)
    {
        k=abs(k);
        int n=(int)sqrt(k);
        for (;;n++)
            if (((n*(n+1)/2)>=k)&&((n*(n+1)/2-k)%2==0))
            {
                printf("%d\n",n);
                break;
            }
    }
    return 0;
}
