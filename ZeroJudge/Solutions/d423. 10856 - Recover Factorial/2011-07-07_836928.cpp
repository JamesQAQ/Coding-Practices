#include <cstdio>

bool p[3000001]={},run[3000001]={};
int prime[3000001]={2},pnum=1,ps[3000001],ans;
void dfs(int x,int d){
	for (int i=d;i<pnum;i++){
		long long temp=(long long)x*prime[i];
		if (temp<=3000000){
			ps[temp]=ps[x]+1;
			run[temp]=true;
			dfs(temp,i);
		}
		else
			break;
	}
}
bool search(int n){
	int l=0,r=3000000,mid;
	while (l<=r){
		mid=(l+r)/2;
		if (ps[mid]>n) r=mid-1;
		else if (ps[mid]<n) l=mid+1;
		else{
			ans=mid;
			return true;
		}
	}
	return false;
}
int main()
{
	for (int i=3;i<3000000;i+=2)
		p[i]=true;
	for (int i=3;i<1732;i+=2)
		if (p[i]){
			prime[pnum++]=i;
			for (int j=i*i;j<3000000;j+=2*i)
				p[j]=false;
		}
	for (int i=1733;i<3000000;i+=2)
		if (p[i])
			prime[pnum++]=i;
	ps[0]=ps[1]=0;
	dfs(1,0);
	for (int i=2;i<=3000000;i++){
		if (run[i])
			ps[i]=ps[i-1]+ps[i];
		else
			ps[i]=ps[i-1]+1;
	}
	int n,cases=0;
	while (scanf("%d",&n)){
		if (n<0)
			break;
		printf("Case %d: ",++cases);
		if (n==0)
			puts("0!");
		else if (search(n))
			printf("%d!\n",ans);
		else
			puts("Not possible.");
	}
	return 0;
}
