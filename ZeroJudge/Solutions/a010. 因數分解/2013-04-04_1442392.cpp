#include <cstdio>

int main()
{
	int n;
	while (scanf("%d",&n)==1){
		bool first=true;
		for (int i=1;i*i<=n;i+=2){
			if (i==1)
				i++;
			if (n%i==0){
				int cnt=0;
				while (n%i==0){
					n/=i;
					cnt++;
				}
				if (first) first=false;
				else printf(" * ");
				if (cnt>1)
					printf("%d^%d",i,cnt);
				else
					printf("%d",i);
			}
			if (i==2)
				i--;
		}
		if (n>1){
			if (first) first=false;
			else printf(" * ");
			printf("%d",n);
		}
		puts("");
	}
}
