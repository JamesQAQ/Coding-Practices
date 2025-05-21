#include <cstdio>
#include <algorithm>

bool p[50000]={};
int prime[50000],pnum=1,qfac[10000],num[10000],qfacnum,fac[10000],fnum;
void dfs(int d,int x){
    if (d==qfacnum){
        fac[fnum++]=x;
        return;
    }
    for (int i=0;i<=num[d];i++){
        dfs(d+1,x);
        x*=qfac[d];
    }
}
int main()
{
    prime[0]=2;
    for (int i=3;i<50000;i+=2)
        p[i]=true;
    for (int i=3;i<224;i+=2)
        if (p[i]){
            prime[pnum++]=i;
            for (int j=i*i;j<50000;j+=2*i)
                p[j]=false;
        }
    for (int i=225;i<50000;i+=2)
        if (p[i])
            prime[pnum++]=i;
    int n;
    while (scanf("%d",&n)==1){
        fnum=qfacnum=0;
        for (int i=0;i<pnum;i++){
            if (prime[i]>n)
                break;
            if (n%prime[i]==0){
                qfac[qfacnum]=prime[i];
                num[qfacnum]=1;
                n/=prime[i];
                while (n%prime[i]==0){
                    n/=prime[i];
                    num[qfacnum]++;
                }
                qfacnum++;
            }
        }
        if (n!=1){
            qfac[qfacnum]=n;
            num[qfacnum]=1;
            qfacnum++;
        }
        dfs(0,1);
        std::sort(fac,fac+fnum);
        printf("%d",fac[0]);
        for (int i=1;i<fnum;i++)
            printf(" %d",fac[i]);
        puts("");
    }
    return 0;
}
