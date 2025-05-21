#include <cstdio>
#define MAX 32000

bool p[MAX+1]={};
int prime[MAX],pnum=1;
void sieve(){
	prime[0]=2;
	for (int i=3;i<MAX;i+=2)
		p[i]=true;
	for (int i=3;i<MAX;i+=2)
		if (p[i]){
			prime[pnum++]=i;
			for (int j=i*i;j<MAX;j+=2*i)
				p[j]=false;
		}
}
int main()
{
	sieve();
	int n;
	while (scanf("%d",&n),n){
		if (n==1){
			puts("0");
			continue;
		}
		int ans=n;
		for (int i=0;i<pnum&&prime[i]*prime[i]<=n;i++)
			if (n%prime[i]==0){
				while (n%prime[i]==0)
					n/=prime[i];
				ans/=prime[i];
				ans*=prime[i]-1;
			}
		if (n>1){
			ans/=n;
			ans*=n-1;
		}
		printf("%d\n",ans);
	}
}
