#include <cstdio>

bool p[1001]={};
int prime[1000],pnum;
void sieve(){
    prime[0]=2,pnum=1;
    for (int i=3;i<=1000;i+=2)
        p[i]=true;
    for (int i=3;i<=1000;i+=2)
        if (p[i]){
            prime[pnum++]=i;
            for (int j=i*i;j<=1000;j+=2*i)
                p[j]=false;
        }    
}

int main()
{
    sieve();
    int n,sum;
    while (scanf("%d",&n),n){
        printf("%d : ",n);
        sum=0;
        for (int i=0;i<pnum;i++){
            if (n==1)
                break;
            if (n%prime[i]==0){
                sum++;
                while (n%prime[i]==0)
                    n/=prime[i];
            }
        }
        printf("%d\n",(n==1)?sum:sum+1);
    }
}
