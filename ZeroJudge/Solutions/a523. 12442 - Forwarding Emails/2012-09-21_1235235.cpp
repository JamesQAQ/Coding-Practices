#include <cstdio>

bool RUN[50001];
int cases,n,to[50001],run[50001],no[50001],cnt[50001],dp[50001];
int DP(int x){
    if (!RUN[x]){
        dp[x]=cnt[x];
        if (no[to[x]]!=x)
            dp[x]+=DP(no[to[x]]);
        RUN[x]=true;
    }
    return dp[x];
}
int main()
{
    int a,b;
    scanf("%d",&cases);
    for (int t=1;t<=cases;t++){
        scanf("%d",&n);
        for (int i=0;i<n;i++){
            scanf("%d %d",&a,&b);
            to[a]=b;
        }
        for (int i=1;i<=n;i++)
            run[i]=-1,no[i]=i,cnt[i]=1,RUN[i]=false;
        for (int i=1;i<=n;i++)
            if (run[i]==-1){
                int at=i;
                while (run[at]==-1){
                    run[at]=i,at=to[at];
                }
                if (run[at]==i){
                    //printf("cycle %d\n",at);
                    int k=to[at];
                    while (k!=at)
                        no[k]=at,k=to[k],cnt[at]++;
                }
            }
        int ans=-1;
        for (int i=1;i<=n;i++)
            if (ans==-1||(DP(no[i])>DP(ans)||(DP(no[i])==DP(ans)&&i<ans)))
                ans=i;
        printf("Case %d: %d\n",t,ans);
    }
}
/*
3
3
1 2
2 3
3 1
4
1 2
2 1
4 3
3 2
5
1 2
2 1
5 3
3 4
4 5
*/
