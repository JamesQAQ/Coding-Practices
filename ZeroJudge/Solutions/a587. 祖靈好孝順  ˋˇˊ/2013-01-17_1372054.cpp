#include <cstdio>

struct Node{
	int w,v;
} item[100];
int max(int a,int b){
	return (a>b)?a:b;
}
int main()
{
	int n,w,dp[10001];
	while (scanf("%d",&n)==1){
		for (int i=0;i<n;i++)
			scanf("%d %d",&item[i].w,&item[i].v);
		scanf("%d",&w);
		for (int i=0;i<=w;i++)
			dp[i]=0;
		for (int i=0;i<n;i++)
			for (int j=w;j>=item[i].w;j--)
				dp[j]=max(dp[j],dp[j-item[i].w]+item[i].v);
		printf("%d\n",dp[w]);
	}
}
