#include <cstdio>

long long gcd(long long a,long long b){
    while ((a%=b)&&(b%=a));
    return (a==0)?b:a;
}
int main()
{
    long long a,b;
    while (scanf("%lld %lld",&a,&b)==2)
        printf("%lld\n",a+b-gcd(a,b));
}
