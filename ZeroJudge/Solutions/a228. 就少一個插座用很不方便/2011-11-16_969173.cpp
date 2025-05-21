#include <cstdio>
#include <iostream>

struct Node {int a[4096];} dp[2],*pre,*now;
int map[11][11],pow2[13],mod=1000000007;
int main()
{
    pow2[0]=1;
    for (int i=1;i<=12;i++)
        pow2[i]=pow2[i-1]<<1;
    pre=&dp[0],now=&dp[1];
    int cases,n,m;
    scanf("%d",&cases);
    for (int t=1;t<=cases;t++){
        scanf("%d %d",&n,&m);
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                scanf("%d",&map[i][j]);
        for (int i=1;i<pow2[m+1];i++)
            now->a[i]=0;
        now->a[0]=1;
        for (int i=0;i<n;i++){
            if (i){
                for (int j=pow2[m+1]-1;j>=pow2[m];j--)
                    now->a[j]=0;
                for (int j=pow2[m]-1;j>0;j--)
                    now->a[j<<1]=now->a[j],now->a[j]=0;
            }
            for (int j=0;j<m;j++){
                std::swap(pre,now);
                if (map[i][j]){
                    for (int k=0;k<pow2[m+1];k++)
                        now->a[k]=0;
                    for (int k=0;k<pow2[m+1];k++)
                        if (pre->a[k]){
                            if ((k&pow2[j])&&(k&pow2[j+1])){
                                int to=k-pow2[j]-pow2[j+1];
                                now->a[to]+=pre->a[k];
                                if (now->a[to]>=mod)
                                    now->a[to]-=mod;
                            }
                            else if (k&pow2[j]){
                                now->a[k]+=pre->a[k];
                                if (now->a[k]>=mod)
                                    now->a[k]-=mod;
                                int to=k-pow2[j]+pow2[j+1];
                                now->a[to]+=pre->a[k];
                                if (now->a[to]>=mod)
                                    now->a[to]-=mod;
                            }
                            else if (k&pow2[j+1]){
                                now->a[k]+=pre->a[k];
                                if (now->a[k]>=mod)
                                    now->a[k]-=mod;
                                int to=k+pow2[j]-pow2[j+1];
                                now->a[to]+=pre->a[k];
                                if (now->a[to]>=mod)
                                    now->a[to]-=mod;
                            }
                            else{
                                int to=k+pow2[j]+pow2[j+1];
                                now->a[to]+=pre->a[k];
                                if (now->a[to]>=mod)
                                    now->a[to]-=mod;
                            }
                        }
                }
                else{
                    for (int k=0;k<pow2[m+1];k++)
                        if (!((k&pow2[j])||(k&pow2[j+1])))
                            now->a[k]=pre->a[k];
                        else
                            now->a[k]=0;
                }
            }
        }
        printf("Case %d: %d\n",t,now->a[0]);
    }
    return 0;
}
