#include <cstdio>

int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0,j=1;i<=n;i++,j<<=1)
		printf("2^%d = %d\n",i,j);
}
