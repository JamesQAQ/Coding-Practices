#include <cstdio>

int len[9]={1,2,3,4,5,6,7,8,10};
int min(int a,int b){
    return (a<b)?a:b;
}
int main()
{
    bool dp[100];
    int n,need[9],maxx=0,sum=0,f[100];
    scanf("%d",&n);
    n-=n%8;
    n/=8;
    for (int i=0;i<9;i++){
        scanf("%d",&need[i]);
        sum+=need[i];
        if (need[i])
            maxx=len[i];
    }
    if (n<maxx)
        puts("NO SOLUTION!!");
    else{
        int ans=0;
        while (sum){
            for (int i=1;i<=n;i++)
                dp[i]=false;
            dp[0]=true;
            for (int i=8;i>=0;i--)
                for (int j=min(n/len[i],need[i]);j>0;j--)
                    for (int k=n;k>=len[i];k--)
                        if (!dp[k])
                            if (dp[k-len[i]]){
                                dp[k]=true;
                                f[k]=i;
                            }
            int at;
            for (int i=n;i>0;i--)
                if (dp[i]){
                    at=i;
                    break;
                }
            while (at){
                int v=len[f[at]];
                need[f[at]]--;
                sum--;
                at=at-len[f[at]];
            }
            ans++;
        }
        printf("%d\n",ans);
    }
}
