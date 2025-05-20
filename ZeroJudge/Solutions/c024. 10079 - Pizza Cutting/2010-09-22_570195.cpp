#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    long long int a;
    while (scanf("%lld",&a))
    {
        if (a<0)
            break;
        printf("%lld\n",(a*a+a+2)/2);
    }
    return 0;
}
