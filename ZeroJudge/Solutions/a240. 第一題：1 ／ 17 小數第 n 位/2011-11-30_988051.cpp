#include <cstdio>

int main()
{
    int at[17];
    int a=1,mod=17,c[100],num=0,sum[100];
    for (int i=0;i<mod;i++)
        at[i]=-1;
    at[1]=0;
    a*=10;
    while (1){
        sum[num]=c[num++]=a/mod;
        a%=mod;
        if (at[a]!=-1)
            break;
        at[a]=num-1;
        a*=10;
    }
    int cases,n;
    for (int i=1;i<num;i++)
        sum[i]+=sum[i-1];
    scanf("%d",&cases);
    while (cases--){
        scanf("%d",&n);
        n--;
        printf("%d %d\n",c[n%num],sum[num-1]*(n/num)+sum[n%num]);
    }
    return 0;
}
