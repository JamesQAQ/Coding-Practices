#include <cstdio>

bool p[2000001];
int main()
{
	for (int i=3;i<=2000000;i+=2)
		p[i]=true;
	long long ans=2;
	for (int i=3;i<=2000000;i+=2)
		if (p[i]){
			ans+=(long long)i;
			for (long long j=(long long)i*i;j<=2000000;j+=2*i)
				p[j]=false;
		}
	printf("%lld\n",ans);
}
