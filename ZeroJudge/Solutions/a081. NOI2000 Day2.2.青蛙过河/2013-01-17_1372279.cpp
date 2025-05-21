#include <cstdio>

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int ans=m+1;
	for (int i=0;i<n;i++)
		ans<<=1;
	printf("%d\n",ans);
}
