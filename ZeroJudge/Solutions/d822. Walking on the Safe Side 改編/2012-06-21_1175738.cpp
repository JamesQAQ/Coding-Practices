#include <cstdio>

int dp[2][3001],*pre,*now,*tmp;
bool map[3001][3001]={};
int main()
{
    int n,m,k,a,b,mod=1000000;
    scanf("%d %d %d",&n,&m,&k);
    pre=dp[0],now=dp[1];
    pre[0]=now[0]=0;
    for (int i=0;i<=m;i++)
        now[i]=0;
    for (int i=0;i<k;i++)
        scanf("%d %d",&a,&b),map[a][b]=true;
    if (map[1][1]||map[n][m]){
        puts("0");
        return 0;
    }
    now[1]=1;
    for (int i=2;i<=m;i++)
        now[i]=(map[1][i])?0:now[i-1];
    for (int i=2;i<=n;i++){
        tmp=now,now=pre,pre=tmp;
        for (int j=1;j<=m;j++){
            now[j]=(map[i][j])?0:now[j-1]+pre[j];
            if (now[j]>=mod)
                now[j]-=mod;
        }
    }
    printf("%d\n",now[m]);
}
