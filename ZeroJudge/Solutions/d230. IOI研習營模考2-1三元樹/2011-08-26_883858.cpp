#include <cstdio>
unsigned long long gcd(unsigned long long m,unsigned long long n){
    while ((m%=n)&&(n%=m));
    return (m==0)?n:m;
}
int main()
{
    int n;
    unsigned long long d[5000],MAX=(unsigned long long)0-1,mod=10000000;
    while (scanf("%d",&n)==1){
        unsigned long long c=2*n+1,cnt=1;
        int num=0;
        for (unsigned long long i=0,j=2*n+1;3*n-i>=j;i++){
            d[num++]=3*n-i;
            while ((3*n-i!=j)&&(MAX/d[i])>=j)
                d[i]*=j,j++;
        }
        for (unsigned long long i=n,j=2;i>=j;i--){
            unsigned long long temp=i;
            while (i!=j&&MAX/temp>=j)
                temp*=j,j++;
            for (int i=0;temp!=1;i++){
                unsigned long long g=gcd(d[i],temp);
                d[i]/=g,temp/=g;
            }
        }
        for (int i=0;c!=1;i++){
            unsigned long long g=gcd(d[i],c);
            d[i]/=g,c/=g;
        }
        for (int i=0;i<num;i++)
            cnt=(cnt*(d[i]%mod))%mod;
        printf("%llu\n",cnt);
    }
    return 0;
}
