#include <cstdio>

long long gcd(long long n,long long m){
    while ((n%=m)&&(m%=n));
    return (n==0)?m:n;
}
int main()
{
    long long A,B,C,n,g;
    while (scanf("%lld",&n)==1){
        A=n*n,B=n*n-1,C=12;
        g=gcd(A,C);
        A/=g,C/=g;
        g=gcd(B,C);
        B/=g;
        printf("%lld\n",A*B);
    }
    return 0;
}
