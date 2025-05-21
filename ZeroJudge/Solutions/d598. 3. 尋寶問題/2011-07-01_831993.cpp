#include <cstdio>

int m,n,p[15],path[20][20],dp[15][32768],pow2[16]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768};
bool run[15][32768]={};
void count(int at,int d){
    if (run[at][d])
        return;
    dp[at][d]=2147483647;
    int td=d-pow2[at];
    for (int i=0;i<n;i++)
        if (pow2[i]&td){
            count(i,td);
            if (dp[i][td]+path[p[i]][p[at]]<dp[at][d])
                dp[at][d]=dp[i][td]+path[p[i]][p[at]];
        }
    run[at][d]=true;
}
int main()
{
    scanf("%d %d",&m,&n);
    for (int i=0;i<n;i++)
        scanf("%d",&p[i]),p[i]--;
    for (int i=0;i<m;i++)
        for (int j=0;j<m;j++)
            scanf("%d",&path[i][j]);
    for (int k=0;k<m;k++)
        for (int i=0;i<m;i++)
            for (int j=0;j<m;j++)
                if (i!=j&&i!=k&&j!=k&&path[i][k]*path[k][j]!=0)
                    if (path[i][j]==0||path[i][k]+path[k][j]<path[i][j])
                        path[i][j]=path[i][k]+path[k][j];
    for (int i=0;i<m;i++)
        path[i][i]=0;
    for (int i=0,j=1;i<n;i++,j<<=1){
        run[i][j]=true;
        dp[i][j]=path[0][p[i]];
    }
    int ans=2147483647,d=pow2[n]-1;
    for (int i=0;i<n;i++){
        count(i,d);
        if (dp[i][d]+path[p[i]][m-1]<ans)
            ans=dp[i][d]+path[p[i]][m-1];
    }
    printf("%d\n",ans);
    return 0;
}
