#include <cstdio>

int dp[65536],pow2[17],n,value[16][16];
bool run[65536];
int cnt(int s){
	if (run[s])
		return dp[s];
	dp[s]=-2147483647;
	run[s]=true;
	for (int i=0;i<n;i++)
		if (s&pow2[i])
			for (int j=i+1;j<n;j++)
				if (s&pow2[j]){
					int x=cnt(s-pow2[i]-pow2[j])+value[i][j];
					if (x>dp[s])
						dp[s]=x;
				}
	return dp[s];
}
int main()
{
	pow2[0]=1;
	for (int i=1;i<17;i++)
		pow2[i]=pow2[i-1]*2;
	while (scanf("%d",&n)==1){
		n*=2;
		for (int i=0;i<n;i++)
			for (int j=0;j<n;j++)
				scanf("%d",&value[i][j]);
		for (int i=0;i<pow2[n];i++)
			run[i]=false;
		run[0]=true,dp[0]=0;
		printf("%d\n",cnt(pow2[n]-1)*10);
	}
	return 0;
}
