#include <cstdio>

int dp[31][31][2]={},sum[31]={};
void init(){
	dp[0][0][0]=1;
	for (int i=0;i<30;i++)
		for (int j=0;j<=i;j++){
			if (j+1>=3)
				dp[i+1][j+1][1]+=dp[i][j][0];
			else
				dp[i+1][j+1][0]+=dp[i][j][0];
			dp[i+1][0][0]+=dp[i][j][0];
			dp[i+1][j+1][1]+=dp[i][j][1];
			dp[i+1][0][1]+=dp[i][j][1];
		}
	for (int i=0;i<=30;i++)
		for (int j=0;j<=i;j++){
			//printf("dp %d %d %d %d\n",i,j,dp[i][j][0],dp[i][j][1]);
			sum[i]+=dp[i][j][1];
		}
}
int main()
{
	init();
	int n;
	while (scanf("%d",&n),n)
		printf("%d\n",sum[n]);
}
