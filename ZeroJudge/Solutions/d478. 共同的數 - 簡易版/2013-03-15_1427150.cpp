#include <cstdio>

int a[200000],b[200000];
bool binarysearch(int l,int r,int x){
	while (l<=r){
		int mid=(l+r)/2;
		if (b[mid]>x)
			r=mid-1;
		else if (b[mid]<x)
			l=mid+1;
		else
			return true;
	}
	return false;
}
int main()
{
	int n,m;
	scanf("%d",&n);
	scanf("%d",&m);
	while (n--){
		for (int i=0;i<m;i++)
			scanf("%d",&a[i]);
		for (int i=0;i<m;i++)
			scanf("%d",&b[i]);
		int ans=0;
		for (int i=0;i<m;i++)
			if (binarysearch(0,m-1,a[i]))
				ans++;
		printf("%d\n",ans);
	}
}
