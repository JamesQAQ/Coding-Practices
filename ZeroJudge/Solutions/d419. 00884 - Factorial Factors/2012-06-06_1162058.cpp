#include <cstdio>

bool p[1000001]={};
int prime[1000000],pnum=1;
void sieve(){
    prime[0]=2;
    for (int i=3;i<=1000000;i+=2)
        p[i]=true;
    for (int i=3;i<=1000;i+=2)
        if (p[i]){
            prime[pnum++]=i;
            for (int j=i*i;j<=1000000;j+=2*i)
                p[j]=false;
        }
    for (int i=1001;i<=1000000;i+=2)
        if (p[i])
            prime[pnum++]=i;
}
int sum[1000001];
void dfs(int x,int d,int cnt){
    sum[x]=cnt;
    for (int i=d;i<pnum;i++){
        long long v=(long long)x*prime[i];
        if (v>1000000)
            break;
        dfs(v,i,cnt+1);
    }
}
int main()
{
    sieve();
    dfs(1,0,0);
    int n;
    for (int i=2;i<=1000000;i++)
        sum[i]+=sum[i-1];
    while (scanf("%d",&n)==1)
        printf("%d\n",sum[n]);
}
