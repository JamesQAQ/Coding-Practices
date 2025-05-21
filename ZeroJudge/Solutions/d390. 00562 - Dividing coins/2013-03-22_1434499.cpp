#include <cstdio>

bool dp[100000];
int main()
{
	int cases,n,a[100];
	scanf("%d",&cases);
	while (cases--){
		scanf("%d",&n);
		int sum=0;
		for (int i=0;i<n;i++)
			scanf("%d",&a[i]),sum+=a[i];
		int limit=sum/2;
		for (int i=0;i<=limit;i++)
			dp[i]=false;
		dp[0]=true;
		for (int i=0;i<n;i++)
			for (int j=limit;j>=a[i];j--)
				if (dp[j-a[i]])
					dp[j]=true;
		int ans=0;
		for (int i=limit;i>=0;i--)
			if (dp[i]){
				ans=i;
				break;
			}
		printf("%d\n",-2*ans+sum);
	}
}
