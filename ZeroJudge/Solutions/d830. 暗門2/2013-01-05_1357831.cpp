#include <cstdio>

int n,m,avg,a[100001],b[100001];
bool judge(int k){
	int l=0,r=0;
	for (int i=1;i<=n;i++){
		int need=avg;
		while (r<m&&b[r]-k<=i)
			r++;
		while (need){
			if (l==r||b[l]+k<i)
				return false;
			l++,need--;
		}
	}
	return true;
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
	while (scanf("%d %d",&n,&m)==2){
		for (int i=1;i<=n;i++)
			a[i]=0;
		for (int i=0;i<m;i++)
			a[input()]++;
		int num=0;
		for (int i=1;i<=n;i++) 
			for (int j=0;j<a[i];j++)
				b[num++]=i;
		avg=m/n;
		int l=0,r=n-1;
		while (l<=r){
			int mid=(l+r)/2;
			if (judge(mid))
				r=mid-1;
			else
				l=mid+1;
		}
		printf("%d\n",l);
	}
}
