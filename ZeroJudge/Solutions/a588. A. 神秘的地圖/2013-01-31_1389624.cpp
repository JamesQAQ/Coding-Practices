#include <cstdio>

int n[2],m[2],now[10];
int path[2][10][10];
bool use[10];
bool ok(int x,int s){
	for (int i=0;i<x;i++)
		if (path[1][now[i]][s]<path[0][i][x])
			return false;
	if (path[1][s][s]<path[0][x][x])
		return false;
	return true;
}
bool dfs(int x){
	if (x==n[0])
		return true;
	for (int i=0;i<n[1];i++)
		if (!use[i]&&ok(x,i)){
			use[i]=true;
			now[x]=i;
			if (dfs(x+1))
				return true;
			use[i]=false;
		}
	return false;
}
int main()
{
	int cases,a,b;
	scanf("%d",&cases);
	while (cases--){
		for (int i=1;i>=0;i--){
			scanf("%d %d",&n[i],&m[i]);
			for (int j=0;j<n[i];j++){
				use[j]=false;
				for (int k=0;k<n[i];k++)
					path[i][j][k]=0;
			}
			for (int j=0;j<m[i];j++){
				scanf("%d %d",&a,&b);
				path[i][a][b]++,path[i][b][a]++;
			}
		}
		puts((dfs(0))?"YES":"NO");
	}
}
