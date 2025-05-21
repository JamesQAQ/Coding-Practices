#include <cstdio>

bool p[10000001]={};
int sum[10000001];
void sieve(){
    p[2]=true;
    for (int i=3;i<=10000000;i+=2)
        p[i]=true;
    for (int i=3;i<=3162;i+=2)
        if (p[i])
            for (int j=i*i;j<=10000000;j+=2*i)
                p[j]=false;
    sum[0]=0;
    for (int i=1;i<=10000000;i++)
        sum[i]=sum[i-1]+p[i];
}
int main()
{
    sieve();
    int cases,a,b;
    scanf("%d",&cases);
    while (cases--){
        scanf("%d %d",&a,&b);
        if (a>b) a^=b^=a^=b;
        printf("%d\n",sum[b]-sum[a-1]);
    }
}
