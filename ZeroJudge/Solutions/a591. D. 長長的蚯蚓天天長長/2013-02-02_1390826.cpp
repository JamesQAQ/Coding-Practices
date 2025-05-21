#include <cstdio>

double dp[10000000],eps=1e-6;
double fabs(double x){
	return (x<0)?-x:x;
}
int main()
{
	int cases,n,s,m;
	scanf("%d",&cases);
	while (cases--){
		scanf("%d %d %d",&n,&m,&s);
		if (s<=n){
			puts("100.0%");
			continue;
		}
		double ans=0;
		dp[0]=100;
		for (int i=1;i<m;i++)
			dp[i]=0;
		double f=-1;
		int cnt=0;
		for (int i=0;i<n;i++){
			//printf("i %d %lf\n",i,dp[i]);
			if (fabs(dp[i]-f)>eps)
				cnt=0;
			else
				cnt++;
			f=dp[i];
			if (cnt==m){
				//puts("=d.3=");
				ans=0;
				for (int i=n-m;i<n;i++){
					double v=f/m;
					for (int j=1;j<=m;j++)
						if (i+j>=s)
							ans+=v;
				}
				break;
			}
			if (i+m<n)
				dp[i+m]=0;
			double v=dp[i]/m;
			for (int j=1;j<=m;j++){
				if (i+j<n)
					dp[i+j]+=v;
				else if (i+j>=s)
					ans+=v;
			}
		}
		printf("%.1lf%%\n",ans);
	}
}
