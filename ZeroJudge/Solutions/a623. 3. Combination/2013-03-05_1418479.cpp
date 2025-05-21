#include <cstdio>

int main()
{
	int n,m;
	while (scanf("%d %d",&n,&m)==2){
		if (n-m<m)
			m=n-m;
		long long ans=1;
		int at=2;
		for (int i=n-m+1;i<=n;i++){
			ans*=i;
			while (at<=m&&ans%at==0)
				ans/=at,at++;
		}
		printf("%lld\n",ans);
	}
}
