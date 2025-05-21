#include <cstdio>
#include <algorithm>

int n,k,t[100000];
struct Custom{
	int id,w;
} cus[100000];
bool cmp(int i,int j){
	return cus[i].id<cus[j].id;
}
bool ok(int limit){
	int sum=0,cnt=0;
	for (int j=0;j<n;j++){
		int i=t[j];
		if (cus[i].w>limit)
			return false;
		if (sum+cus[i].w>limit){
			sum=cus[i].w;
			cnt++;
		}
		else
			sum+=cus[i].w;
		if (cnt>k)
			return false;
	}
	cnt++;
	//printf("limit %d %d\n",limit,cnt);
	return cnt<=k;
}
int input(){
	char c=getchar();
	while (c>'9'||c<'0') c=getchar();
	int x=c-48;c=getchar();
	while (c<='9'&&c>='0') x=x*10+c-48,c=getchar();
	return x;
}
int main()
{
	int cases;
	cases=input();
	while (cases--){
		n=input(),k=input();
		for (int i=0;i<n;i++)
			cus[i].id=input(),cus[i].w=input(),t[i]=i;
		std::stable_sort(t,t+n,cmp);
		int l=0,r=10000000;
		while (l<=r){
			int mid=(l+r)/2;
			if (ok(mid))
				r=mid-1;
			else
				l=mid+1;
		}
		printf("%d\n",l);
	}
}
