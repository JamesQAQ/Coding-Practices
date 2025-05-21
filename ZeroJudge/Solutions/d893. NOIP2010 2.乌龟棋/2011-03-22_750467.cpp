#include <iostream>
using namespace std;

int dp[41][41][41][41]={};
int main()
{
    int score[350],n,m,card[5]={},temp;
    scanf("%d %d",&n,&m);
    for (int i=0;i<n;i++)
        scanf("%d",&score[i]);
    for (int i=0;i<m;i++)
    {
        scanf("%d",&temp);
        card[temp]++;
    }
    dp[0][0][0][0]=score[0];
    for (int i=0;i<=card[1];i++)
        for (int j=0;j<=card[2];j++)
            for (int k=0;k<=card[3];k++)
                for (int l=0;l<=card[4];l++)
                {
                    int at=i*1+j*2+k*3+l*4;
                    if (i>0)
                        dp[i][j][k][l]=max(dp[i][j][k][l],dp[i-1][j][k][l]+score[at]);
                    if (j>0)
                        dp[i][j][k][l]=max(dp[i][j][k][l],dp[i][j-1][k][l]+score[at]);
                    if (k>0)
                        dp[i][j][k][l]=max(dp[i][j][k][l],dp[i][j][k-1][l]+score[at]);
                    if (l>0)
                        dp[i][j][k][l]=max(dp[i][j][k][l],dp[i][j][k][l-1]+score[at]);
                }
    cout<<dp[card[1]][card[2]][card[3]][card[4]]<<endl;
    //system("pause"); 
    return 0;
}
