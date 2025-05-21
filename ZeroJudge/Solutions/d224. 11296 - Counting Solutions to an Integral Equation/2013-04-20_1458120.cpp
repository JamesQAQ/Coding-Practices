#include <cstdio>

int main()
{
	int n;
	while (scanf("%d",&n)==1){
		long long c=n/2+1;
		printf("%lld\n",((c+1)*c)/2);
	}
}
