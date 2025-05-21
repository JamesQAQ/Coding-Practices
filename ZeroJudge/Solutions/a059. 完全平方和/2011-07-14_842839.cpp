#include <cstdio>

int sum[1001];
bool ok[1001]={};
int main()
{
    for (int i=1;i<=10;i++)
        ok[i*i]=true;
    sum[0]=0;
    for (int i=1;i<=1000;i++)
        sum[i]=(ok[i])?sum[i-1]+i:sum[i-1];
    int cases,a,b;
    while (scanf("%d",&cases)==1)
        for (int t=1;t<=cases;t++){
            scanf("%d %d",&a,&b);
            printf("Case %d: %d\n",t,sum[b]-sum[a-1]);
        }
    return 0;
}
