#include <cstdio>

char s[100001];
int n,all;
char dfs(int x){
	//printf("dfs %d\n",x);
	if (x>all-1){
		putchar((s[x-all]=='1')?'I':'B');
		return (s[x-all]=='1')?'I':'B';
	}
	char a=dfs(2*x);
	char b=dfs(2*x+1);
	char c;
	if (a=='F'||b=='F'||a!=b)
		c='F';
	else
		c=a;
	putchar(c);
}
int main()
{
	int n;
	scanf("%d",&n);
	all=(1<<n);
	scanf("%s",s);
	dfs(1);
	puts("");
}
