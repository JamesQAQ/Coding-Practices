#include <cstdio>

int st[10000],n,m;
bool mark[10001],use[10001]={};
int now[10000],ans=0;
void dfs(int x){
	if (x==n){
		ans++;
		if (ans==m+1){
			for (int i=0;i<n;i++)
				printf((i)?" %d":"%d",now[i]);
			puts("");
		}
		return;
	}
	int i=1;
	if (mark[x]){
		i=st[x];
		mark[x]=false;
	}
	for (;i<=n;i++)
		if (!use[i]){
			use[i]=true;
			now[x]=i;
			dfs(x+1);
			if (ans==m+1)
				return;
			use[i]=false;
		}
}
int main()
{
	scanf("%d %d",&n,&m);
	for (int i=0;i<n;i++){
		mark[i]=true;
		scanf("%d",&st[i]);
	}
	dfs(0);
}
/*
5
3
1 2 3 4 5
*/
