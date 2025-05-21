#include <stdio.h>
#include <vector>
#include <algorithm>

int dp[51][2001],sdp[51][2001];
int a[51];
std::vector <int> path[51][2001];

int tmp[51];

#define MAX 10000
int answer[MAX][51],counter=0;

void dfs(int x,int v,int num){
	if (v==0){
		
		for (int i=0;i<num;i++)
			answer[counter][i]=tmp[i];
		std::stable_sort(answer[counter],answer[counter]+num);
			
		counter++;
		return;
	}
	int p=path[x][v].size();
	for (int i=0;i<p;i++){
		int to=path[x][v][i];
		if (v-to>0){
			tmp[num]=v-to;
			dfs(x-1,to,num+1);
		}
		else
			dfs(x-1,to,num);
	}
}
int t[MAX],NUM;
bool cmp(int i,int j){
	for (int k=0;k<NUM;k++){
		if (answer[i][k]<answer[j][k])
			return true;
		if (answer[i][k]>answer[j][k])
			return false;
	}
	return true;
}
int main()
{
	int W,n;
	scanf("%d %d",&W,&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (int i=0;i<=W;i++)
		dp[0][i]=n;
	dp[0][0]=0;
	sdp[0][0]=1;
	for (int i=1;i<=n;i++)
		for (int j=0;j<=W;j++){
			dp[i][j]=dp[i-1][j];
			sdp[i][j]=sdp[i-1][j];
			path[i][j].clear();
			path[i][j].push_back(j);
			if (j-a[i]>=0){
				if (dp[i-1][j-a[i]]+1<dp[i][j]){
					dp[i][j]=dp[i-1][j-a[i]]+1;
					sdp[i][j]=sdp[i-1][j-a[i]];
					path[i][j].clear();
					path[i][j].push_back(j-a[i]);
				}
				else if (dp[i-1][j-a[i]]+1==dp[i][j]){
					sdp[i][j]+=sdp[i-1][j-a[i]];
					path[i][j].push_back(j-a[i]);
				}
			}
		}
	printf("%d %d\n",dp[n][W],sdp[n][W]);
	dfs(n,W,0);
	
	NUM=dp[n][W];
	
	for (int i=0;i<counter;i++)
		t[i]=i;
	
	std::stable_sort(t,t+counter,cmp);
	
	for (int k=0;k<counter;k++){
		int i=t[k];
		for (int j=0;j<NUM;j++)
			printf((j)?" %d":"%d",answer[i][j]);
		puts("");
	}
}
