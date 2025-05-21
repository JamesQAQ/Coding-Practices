#include <cstdio>
#define SIZE 2124

int n,all;
int AB[SIZE],cost[SIZE],F[SIZE][SIZE],tree[SIZE][SIZE+1][2];
//A=1 B=0
//for tree   leaf to node leftsubtree and rightsubtree
int dfs_sum(int x,int no){
	if (x>=all)
		return F[x-all][no];
	tree[no][x][0]=dfs_sum(2*x,no);
	tree[no][x][1]=dfs_sum(2*x+1,no);
	return tree[no][x][0]+tree[no][x][1];
}
int dp[2148][SIZE+1],MAX=2147483647;
bool run[2148][SIZE+1]={};
int min(int a,int b){
	return (a<b)?a:b;
}
int max(int a,int b){
	return (a>b)?a:b;
}
int dfs_dp(int x,int s,int dfn,int num){
	if (!run[x][s]){
		int choseA=s/(1<<dfn);
		int fathers=s%(1<<dfn);
		if (x<all){
			dp[x][s]=MAX;
			for (int i=max(0,choseA-num/2);i<=choseA&&i<=num/2;i++)
				dp[x][s]=min(dp[x][s],dfs_dp(2*x,((i*(1<<dfn)+fathers)<<1)+((choseA<=num/2)?1:0),dfn+1,num/2)+dfs_dp(2*x+1,(((choseA-i)*(1<<dfn)+fathers)<<1)+((choseA<=num/2)?1:0),dfn+1,num/2));
		}
		else{
			dp[x][s]=(choseA!=AB[x-all])?cost[x-all]:0;
			int tmp=x;
			for (int i=0,j=1;i<dfn;i++,j<<=1){
				//printf("%d %d\n",i,j);
				if (((j&fathers)>0)==choseA)
					dp[x][s]+=tree[x-all][tmp/2][1-tmp%2];//printf("%d\n",tree[x-all][tmp/2][1-tmp%2]);
				tmp/=2;
			}
		}
		run[x][s]=true;
		//if (x>=all)
		//	printf("dp %d %d %d , %d\n",x,choseA,fathers,dp[x][s]);
	}
	return dp[x][s];
}
int main()
{
	scanf("%d",&n);
	all=(1<<n);
	for (int i=0;i<all;i++)
		scanf("%d",&AB[i]);
	for (int i=0;i<all;i++)
		scanf("%d",&cost[i]);
	for (int i=0;i<all;i++)
		F[i][i]=0;
	for (int i=0;i<all;i++)
		for (int j=i+1;j<all;j++)
			scanf("%d",&F[i][j]),F[j][i]=F[i][j];
	for (int i=0;i<all;i++)
		dfs_sum(1,i);
	int ans=dfs_dp(1,0,0,all);
	for (int i=1;i<=all;i++){
		int p=dfs_dp(1,i,0,all);
		if (p<ans)
			ans=p;
	}
	printf("%d\n",ans);
}
