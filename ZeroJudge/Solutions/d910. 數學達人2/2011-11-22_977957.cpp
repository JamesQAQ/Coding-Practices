#include <cstdio>

unsigned long long n1(int n){
    bool t=true;
    int a=n,b=n-1;
    if (t&&a%2==0)
        a/=2,t=false;
    if (t&&b%2==0)
        b/=2,t=false;
    return (unsigned long long)a*b;
}
unsigned long long n2(int n){
    bool t1=true,t2=true;
    int a=n,b=n-1,c=2*n-1;
    if (t1&&a%2==0)
        a/=2,t1=false;
    if (t1&&b%2==0)
        b/=2,t1=false;
    if (t1&&c%2==0)
        c/=2,t1=false;
    if (t2&&a%3==0)
        a/=3,t2=false;
    if (t2&&b%3==0)
        b/=3,t2=false;
    if (t2&&c%3==0)
        c/=3,t2=false;
    return (unsigned long long)a*b*c;
}
int main()
{
    int n,m;
    while (scanf("%d %d",&n,&m)==2){
        int mini=(n>m)?m:n;
        unsigned long long a=n1(mini),b=n2(mini),c=a*a;
        printf("%llu\n",a*n*m-(n+m)*b+c);
    }
    return 0;
}
