#include <cstdio>

int main()
{
	int dp[100]={1,1,2};
	for (int i=3;i<=76;i++)
		dp[i]=dp[i-2]+dp[i-3];
	int n;
	while (scanf("%d",&n)==1)
		printf("%d\n",dp[n]);
}
