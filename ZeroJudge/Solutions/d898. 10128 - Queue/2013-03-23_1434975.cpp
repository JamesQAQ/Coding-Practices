#include <cstdio>

int dp[14][14][14]={};
void init(){
	dp[1][1][1]=1;
	for (int i=1;i<13;i++)
		for (int j=1;j<13;j++)
			for (int k=1;k<13;k++){
				dp[i+1][j+1][k]+=dp[i][j][k];
				dp[i+1][j][k+1]+=dp[i][j][k];
				dp[i+1][j][k]+=dp[i][j][k]*(i-1);
			}
}
int main()
{
	init();
	int cases,n,p,r;
	scanf("%d",&cases);
	while (cases--){
		scanf("%d %d %d",&n,&p,&r);
		printf("%d\n",dp[n][p][r]);
	}
}
