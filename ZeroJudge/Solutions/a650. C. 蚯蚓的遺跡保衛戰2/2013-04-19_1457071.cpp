#include <cstdio>
#include <algorithm>

int p[100000],b[100000],t[100000];
bool cmp(int i,int j){
	if (p[i]==0)
		return true;
	if (p[j]==0)
		return false;
	return b[i]*p[j]>b[j]*p[i];
}
long long gcd(long long m,long long n){
	while ((m%=n)&&(n%=m));
	return (m==0)?n:m;
}
int main()
{
	int n,cases;
	scanf("%d",&cases);
	while (cases--){
		scanf("%d",&n);
		long long alltime=0;
		for (int i=0;i<n;i++)
			scanf("%d %d",&p[i],&b[i]),t[i]=i,alltime+=p[i];
		alltime++;
		std::stable_sort(t,t+n,cmp);
		long long ans=alltime-1;
		int sump=1;
		for (int j=0;j<n-1;j++){
			int i=t[j];
			sump+=p[i];
			ans+=(long long)(alltime-sump)*b[i];
		}
		long long g=gcd(ans,alltime);
		ans/=g,alltime/=g;
		printf("%lld %lld\n",ans,alltime);
	}
}
