#include <cstdio>

int n,k,p,color[200010],cost[200010],sum[50][200010]={};
int input(){
    char c=getchar();
    while (c==' '||c=='\n')
        c=getchar();
    int x=c-48;
    c=getchar();
    while (c<='9'&&c>='0'){
        x=x*10+c-48;
        c=getchar();
    }
    return x;
}
int main()
{
    scanf("%d %d %d",&n,&k,&p);
    for (int i=1;i<=n;i++){
        color[i]=input();
        cost[i]=input();
    }
    for (int i=0;i<k;i++){
        sum[i][0]=0;
        for (int j=1;j<=n;j++)
            sum[i][j]=sum[i][j-1]+(color[j]==i);
    }
    int at=1;
    long long ans=0;
    for (int i=1;i<=n;i++){
        while (at<=n&&(at<i||cost[at]>p))
            at++;
        if (at>n)
            break;
        ans+=(long long)sum[color[i]][n]-((at==i)?sum[color[i]][at]:sum[color[i]][at-1]);
    }
    printf("%lld\n",ans);
    return 0;
}
