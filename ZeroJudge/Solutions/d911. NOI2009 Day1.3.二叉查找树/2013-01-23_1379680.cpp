#include <cstdio>
#include <algorithm>

struct Node{
	int w,v,f;
} node[100];
long long fsum[100];
bool wcmp(Node i,Node j){
	return i.w<j.w;
}
bool vcmp(Node i,Node j){
	return i.v<j.v;
}
long long dp[70][70][141];
bool run[70][70]={};
int num,k;
long long sumof(int l,int r){
	if (l)
		return fsum[r]-fsum[l-1];
	else
		return fsum[r];
}
void DP(int l,int r){
	if (!run[l][r]){
		run[l][r]=true;
		if (l==r){
			for (int i=num-1;i>=0;i--)
				dp[l][r][i]=node[l].f+((i==node[l].w)?0:k);
			//只有一點，為邊界條件 
			long long mini=dp[l][r][num-1];
			for (int i=num-2;i>=0;i--){
				if (dp[l][r][i]<mini)
					mini=dp[l][r][i];
				dp[l][r][i]=mini;
			}
			//將dp[l][r][i]變成 dp[l][r][i~num-1]的最小值 
		}
		else{
			long long v;
			DP(l+1,r);
			for (int j=l+1;j<r;j++)
				DP(l,j-1),DP(j+1,r);
			DP(l,r-1);
			//預先算好所有會用到的部分 
			for (int i=num-1;i>=0;i--){
				dp[l][r][i]=((node[l].w==i)?0:k)+dp[l+1][r][i];
				//以l為根  左子樹為空 
				for (int j=l+1;j<r;j++){
					v=((node[j].w==i)?0:k)+dp[l][j-1][i]+dp[j+1][r][i];
					if (v<dp[l][r][i])
						dp[l][r][i]=v;
					//枚舉l+1~r-1為根 
				}
				v=((node[r].w==i)?0:k)+dp[l][r-1][i];
				if (v<dp[l][r][i])
					dp[l][r][i]=v;
				//以r為根  右子樹為空 
				dp[l][r][i]+=sumof(l,r);
			}
			long long mini=dp[l][r][num-(r-l+1)];
			for (int i=num-1;i>=0;i--){
				if (dp[l][r][i]<mini)
					mini=dp[l][r][i];
				dp[l][r][i]=mini;
			}
			//將dp[l][r][i]變成 dp[l][r][i~num-1]的最小值 
		}
		
	}
}
int main()
{
	int n;
	scanf("%d %d",&n,&k);
	for (int i=0;i<n;i++)
		scanf("%d",&node[i].v);
	for (int i=0;i<n;i++)
		scanf("%d",&node[i].w);
	for (int i=0;i<n;i++)
		scanf("%d",&node[i].f);
	std::stable_sort(node,node+n,wcmp);
	num=0;
	int f=-1;
	for (int i=0;i<n;i++){
		if (node[i].w!=f){
			f=node[i].w;
			num++;
		}
		node[i].w=num-1;
	}
	//先以權重排序，離散化 
	std::stable_sort(node,node+n,vcmp);
	fsum[0]=node[0].f;
	for (int i=1;i<n;i++)
		fsum[i]=fsum[i-1]+node[i].f;
	//再以值排序 
	DP(0,n-1);
	printf("%lld\n",dp[0][n-1][0]);
}
