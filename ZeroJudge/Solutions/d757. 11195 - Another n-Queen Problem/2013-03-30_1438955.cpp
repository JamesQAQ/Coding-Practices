#include <cstdio>

char map[20][20];
int s[20];
int n,ans;
void dfs(int x,int L,int R,int C){
	//printf("dfs %d %d %d %d\n",x,L,R,C);
	if (x==n){
		ans++;
		return;
	}
	int ok=(~(L|R|s[x]|C))&((1<<n)-1);
	//printf("%d\n",ok);
	while (ok){
		int p=ok&(-ok);
		dfs(x+1,(L+p)<<1,(R+p)>>1,C+p);
		ok-=p;
	}
}
int main()
{
	int cases=0;
	while (scanf("%d",&n)){
		if (n==0)
			break;
		for (int i=0;i<n;i++){
			scanf("%s",map[i]);
			s[i]=0;
			for (int j=0;j<n;j++)
				s[i]=s[i]*2+((map[i][j]=='*')?1:0);
		}
		ans=0;
		dfs(0,0,0,0);
		printf("Case %d: %d\n",++cases,ans);
	}
}
/*
8
........
........
........
........
........
........
........
........
4
.*..
....
....
....

0100

*/
