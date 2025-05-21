#include <cstdio>
#define MAX 10000

bool p[MAX+1];
int prime[MAX],pnum,mod=76543;
void sieve(){
    pnum=1;
    prime[0]=2;
    for (int i=3;i<MAX;i+=2)
        p[i]=true;
    for (int i=3;i<MAX;i+=2)
        if (p[i]){
            prime[pnum++]=i;
            for (int j=i*i;j<MAX;j+=2*i)
                p[j]=false;
        }
}
int pow(int x,int n){
    long long s=1;
    for (int i=1<<13;i>0;i>>=1)
        if (i<=n){
            s*=s;
            s%=mod;
            if (i&n){
                s*=x;
                s%=mod;
            }
        }
    return s;
}
int main()
{
    sieve();
    int at=0,n;
    long long ans=1;
    while (scanf("%d",&n)==1){
        if (ans==0)
            break;
        ans*=pow(prime[at],n);
        ans%=mod;
        at++;
    }
    printf("%lld\n",ans);
    //while (1);
}
