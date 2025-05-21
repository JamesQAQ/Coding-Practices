#include <cstdio>

bool p[70000]={};
int prime[70000],pnum=1;
void sieve(){
    prime[0]=2;
    for (int i=3;i<65536;i+=2)
        p[i]=true;
    for (long long i=3;i<65536;i+=2)
        if (p[i]){
            prime[pnum++]=i;
            for (long long j=i*i;j<65536;j+=2*i)
                p[j]=false;
        }
}
int main()
{
    sieve();
    long long n;
    while (scanf("%lld",&n),n>=0){
        if (n==0)
            puts("Answer Is Too Big!");
        else if (n==1)
            puts("Nothing");
        else{
            long long ans=0;
            for (int i=0;i<pnum&&prime[i]<=n;i++)
                if (n%prime[i]==0){
                    ans=prime[i];
                    while (n%prime[i]==0)
                        n/=prime[i];
                }
            printf("%lld\n",(n==1)?ans:n);
        }
    }
    puts("別鬧了  這明明很簡單");
}
