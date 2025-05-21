#include <cstdio>

int main()
{
	int n;
	while (scanf("%d",&n)==1){
		if (n%2)
			puts("-1");
		else{
			printf("2 1");
			for (int i=3;i<=n;i+=2)
				printf(" %d %d",i+1,i);
			puts("");
		}
	}
}
