#include <cstdio>

bool p[10001];
int prime[10001],pnum;
void sieve(){
    prime[0]=2,pnum=1;
    for (int i=3;i<=10000;i+=2)
        p[i]=true;
    for (int i=3;i<=100;i+=2)
        if (p[i]){
            prime[pnum++]=i;
            for (int j=i*i;j<=10000;j+=2*i)
                p[j]=false;
        }
    for (int i=101;i<=10000;i+=2)
        if (p[i])
            prime[pnum++]=i;
}
bool primetest(int x){
    for (int i=0;i<pnum&&prime[i]*prime[i]<=x;i++)
        if (x%prime[i]==0)
            return false;
    return true;
}
double eps=1e-6;
int main()
{
    sieve();
    int sum[10001];
    sum[0]=1;
    for (int i=1;i<=10000;i++)
        sum[i]=sum[i-1]+primetest(i*i+i+41);
    int a,b;
    while (scanf("%d %d",&a,&b)==2)
        printf("%.2lf\n",(sum[b]-((a)?sum[a-1]:0))/((double)b-a+1)*100+eps);
}
