#include <cstdio>

int main()
{
    int cases,g,k,r,dp[2][10000],*pre,*now,*tmp,mod=1000000007;
    pre=dp[0],now=dp[1];
    scanf("%d",&cases);
    while (cases--){
        scanf("%d %d %d",&g,&k,&r);
        for (int i=1;i<k;i++)
            now[i]=0;
        now[0]=1;
        int temp;
        for (int i=0;i<g;i++){
            scanf("%d",&temp);
            temp%=k;
            tmp=pre,pre=now,now=tmp;
            for (int j=0;j<k;j++)
                now[j]=0;
            for (int j=0;j<k;j++)
                if (pre[j]){
                    int v1=j+temp;
                    if (v1>=k) v1-=k;
                    now[v1]+=pre[j];
                    if (now[v1]>=mod) now[v1]-=mod;
                    int v2=j-temp;
                    if (v2<0) v2+=k;
                    now[v2]+=pre[j];
                    if (now[v2]>=mod) now[v2]-=mod;
                }
        }
        printf("%d\n",now[r]);
    }
}
