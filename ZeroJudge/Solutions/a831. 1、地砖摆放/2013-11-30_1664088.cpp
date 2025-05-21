#include <stdio.h>

int main()
{
    long long a,b,c;
    scanf("%lld %lld %lld",&a,&b,&c);
    printf("%lld\n",((a-1)/c+1)*((b-1)/c+1));
}
