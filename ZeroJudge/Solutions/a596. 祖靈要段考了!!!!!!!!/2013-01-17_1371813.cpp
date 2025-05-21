#include <cstdio>
#define MAX 40000
#define mod 12345

int single[MAX+1],dp[2][MAX+1],a[1500];
//0 down 1 up
void init(int t[]){
	for (int i=0;i<=MAX;i++)
		t[i]=0;
}
int query(int x,int t[]){
	int sum=0;
	while (x>0){
		sum=(sum+t[x])%mod;
		x-=x&(-x);
	}
	return sum;
}
void update(int x,int v,int t[]){
	while (x<=MAX){
		t[x]=(t[x]+v)%mod;
		x+=x&(-x);
	}
}
int main()
{
	int n;
	while (scanf("%d",&n)==1){
		for (int i=0;i<n;i++)
			scanf("%d",&a[i]),a[i]++;
		init(single);
		init(dp[0]);
		init(dp[1]);
		int ans=0;
		for (int i=0;i<n;i++){
			int v=query(a[i]-1,dp[0]);
			//printf("v %d\n",v);
			ans=(ans+v)%mod;
			update(a[i],v,dp[1]);
			v=query(MAX,dp[1])-query(a[i],dp[1]);
			if (v<0) v+=mod;
			//printf("vv %d\n",v);
			ans=(ans+v)%mod;
			update(a[i],v,dp[0]);
			v=query(a[i]-1,single);
			//printf("vvv %d\n",v);
			update(a[i],v,dp[1]);
			v=query(MAX,single)-query(a[i],single);
			if (v<0) v+=mod;
			//printf("vvvv %d\n",v);
			update(a[i],v,dp[0]);
			update(a[i],1,single);
		}
		printf("%d\n",ans);
	}
}
