#include <stdio.h>

int map[50][50];
bool v[50][50];
bool in(int x,int y,int n,int m){
	return x>=0&&y>=0&&x<n&&y<m;
}
int move[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int max(int a,int b){
	return (a>b)?a:b;
}
int dfs(int x,int y,int n,int m,int h){
	int sum=1;
	v[x][y]=true;
	for (int i=0;i<4;i++){
		int xx=x+move[i][0],yy=y+move[i][1];
		if (in(xx,yy,n,m)&&map[xx][yy]==h&&!v[xx][yy])
			sum+=dfs(xx,yy,n,m,h);
	}
	return sum;
}
int work(int n,int m,int h){
	int ans=0;
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
			v[i][j]=false;
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
			if (map[i][j]==h&&!v[i][j])
				ans=max(ans,dfs(i,j,n,m,h));
	return (ans>=2)?ans:0;
}
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
			scanf("%d",&map[i][j]);
	int q;
	scanf("%d",&q);
	for (int i=0;i<q;i++){
		int h;
		scanf("%d",&h);
		printf("%d\n",work(n,m,h));
	}
}
