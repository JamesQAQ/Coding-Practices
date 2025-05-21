#include <cstdio>

int main()
{
	long long f[100];
	f[0]=1,f[1]=1;
	for (int i=2;i<=80;i++)
		f[i]=f[i-1]+f[i-2];
	int n;
	while (scanf("%d",&n),n)
		printf("%lld\n",f[n]);
}
