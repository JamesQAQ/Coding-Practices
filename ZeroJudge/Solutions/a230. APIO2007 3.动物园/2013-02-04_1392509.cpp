#include <cstdio>
#include <vector>

int n,pow[6]={1,2,4,8,16,32},dp[10001][32],ans=0;
struct Node {int like,hate;} tmp;
std::vector <Node> check[10000];
void work(int st){
    int full=32;
    for (int i=0;i<=n;i++)
        for (int j=0;j<full;j++)
            dp[i][j]=-1;
    dp[0][st]=0;
    for (int i=0;i<n-5;i++)
        for (int j=0;j<full;j++)
            if (dp[i][j]!=-1){
                int p=check[i].size();
                for (int k=0;k<p;k++)
                    if ((check[i][k].like&j)||((check[i][k].hate&j)!=check[i][k].hate))
                        dp[i][j]++;
                int to=(j>>1)+16;
                if (dp[i+1][to]==-1||dp[i][j]>dp[i+1][to])
                    dp[i+1][to]=dp[i][j];
                to=(j>>1);
                if (dp[i+1][to]==-1||dp[i][j]>dp[i+1][to])
                    dp[i+1][to]=dp[i][j];
            }
    for (int i=n-5;i<n;i++)
        for (int j=0;j<full;j++)
            if (dp[i][j]!=-1){
                int p=check[i].size();
                for (int k=0;k<p;k++)
                    if ((check[i][k].like&j)||((check[i][k].hate&j)!=check[i][k].hate))
                        dp[i][j]++;
                int to=(j>>1)+((pow[(i+5)-n]&st)?16:0);
                if (dp[i+1][to]==-1||dp[i][j]>dp[i+1][to])
                    dp[i+1][to]=dp[i][j];
            }
    if (dp[n][st]>ans)
        ans=dp[n][st];
}
int main()
{
    int c,e,x,y,temp;
    scanf("%d %d",&n,&c);
    for (int i=0;i<c;i++){
        scanf("%d",&e);
        e--;
        scanf("%d %d",&x,&y);
        tmp.like=tmp.hate=0;
        for (int j=0;j<x;j++){
            scanf("%d",&temp);
            temp--;
            if (temp<e)
                temp+=n;
            tmp.like+=pow[temp-e];
        }
        for (int j=0;j<y;j++){
            scanf("%d",&temp);
            temp--;
            if (temp<e)
                temp+=n;
            tmp.hate+=pow[temp-e];
        }
        check[e].push_back(tmp);
    }
    int full=32;
    for (int i=0;i<32;i++)
        work(i);
    printf("%d\n",ans);
}
