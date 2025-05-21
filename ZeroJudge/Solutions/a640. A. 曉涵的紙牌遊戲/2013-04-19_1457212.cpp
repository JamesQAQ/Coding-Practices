#include <cstdio>

int n,p,l[10],se[10][10];
int ans;
void get(int x){
	scanf("%d",&l[x]);
	for (int i=0;i<l[x];i++){
		scanf("%d",&se[x][i]);
		se[x][i]--;
	}
}
int now[10];
bool check(int x,int pos){
	for (int i=0;i<l[x];i++)
		if (se[x][i]!=now[pos+i])
			return false;
	return true;
}
bool match(int x,int len){
	for (int i=0;i<=len-l[x];i++)
		if (check(x,i))
			return true;
	return false;
}
bool ok(int len){
	for (int i=0;i<p;i++)
		if (match(i,len))
			return false;
	return true;
}
void dfs(int x,int len){
	if (x==n){
		/*for (int i=0;i<len;i++)
			printf("%d ",now[i]);
		puts("");
		getchar();*/
		if (len>1&&ok(len))
			ans++;
		return;
	}
	now[len]=x;
	dfs(x+1,len+1);
	dfs(x+1,len);
}
int main()
{
	int cases;
	scanf("%d",&cases);
	while (cases--){
		scanf("%d %d",&n,&p);
		for (int i=0;i<p;i++)
			get(i);
		ans=0;
		dfs(0,0);
		if (ans)
			printf("%d\n",ans);
		else
			puts("so sad");
	}
	
}

/*
4
5
3
3 2 3 4
2 2 3
2 2 4
7
2
2 1 2
2 6 7
5
4
5 1 2 3 4 5
5 1 2 3 4 5
5 1 2 3 4 5
5 1 2 3 4 5
3
4
2 1 2
2 2 3
2 1 3
3 1 2 3
*/
