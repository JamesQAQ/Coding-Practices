#include <cstdio>

int main()
{
	int a[10],n;
	while (scanf("%d",&a[0])==1){
		for (int i=1;i<10;i++)
			scanf("%d",&a[i]);
		scanf("%d",&n);
		int ans=0;
		for (int i=0;i<10;i++)
			if (n+30>=a[i])
				ans++;
		printf("%d\n",ans);
	}
}
