#include <cstdio>
#include <algorithm>

int a[1000000];
int input(){
	char c=getchar();
	while (c==' '||c=='\n')
		c=getchar();
	int x=c-48;
	c=getchar();
	while (c!=' '&&c!='\n'){
		x=x*10+c-48;
		c=getchar();
	}
	return x;
}
int main()
{
	int n;
	while (scanf("%d",&n)==1){
		for (int i=0;i<n;i++)
			a[i]=input();
		std::sort(a,a+n);
		for (int i=0;i<n;i++){
			if (i)
				putchar(' ');
			printf("%d",a[i]);
		}
		puts("");
	}
	return 0;
}
