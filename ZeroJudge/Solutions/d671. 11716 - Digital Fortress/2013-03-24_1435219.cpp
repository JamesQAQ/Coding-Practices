#include <cstdio>
#include <cstring>

int p[10010]={};
void init(){
	for (int i=0;i*i<=10000;i++)
		p[i*i]=i;
}
char s[10010];
int main()
{
	init();
	int cases;
	scanf("%d",&cases);
	gets(s);
	while (cases--){
		gets(s);
		int len=strlen(s),l=p[len];
		if (p[len]){
			for (int i=0;i<len;i++)
				putchar(s[i/l+(i%l)*l]);
			puts("");
		}
		else
			puts("INVALID");
	}
}
