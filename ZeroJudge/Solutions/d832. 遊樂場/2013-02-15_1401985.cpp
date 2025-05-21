#include <cstdio>

int a[50001],g[50001],sum[50001];
int main()
{
	int cases,n;
	while (scanf("%d",&n)==1){
		scanf("%d",&cases);
		for (int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		sum[0]=0;
		for (int i=1;i<=n;i++)
			sum[i]=sum[i-1]+a[i];
		g[0]=0;
		int mini=0;
		for (int i=1;i<=n;i++){
			g[i]=sum[i]-mini;
			if (sum[i]<mini)
				mini=sum[i];
		}
		for (int i=2;i<=n;i++)
			if (g[i-1]>g[i])
				g[i]=g[i-1];
		int maxx=g[1]-sum[1];
		int ans=-2147483647;
		for (int i=2;i<=n;i++){
			//printf("i %d v %d %d\n",i,sum[i],maxx);
			if (sum[i]+maxx>ans)
				ans=sum[i]+maxx;
			if (g[i]-sum[i]>maxx)
				maxx=g[i]-sum[i];
		}
		printf("%d\n",ans);
	}
}
