#include <cstdio>
#include <algorithm>

int a[10000],*p[10000],c[10000];
bool cmp(int *i,int *j){
	return (*i)<(*j);
}
long long tree[100000];
void init(int at,int l,int r){
	tree[at]=0;
	if (l==r)
		return;
	int mid=(l+r)/2;
	init(2*at,l,mid);
	init(2*at+1,mid+1,r);
}
long long Max;
void query(int at,int l,int r,int dl,int dr){
	if (dl<=l&&r<=dr){
		if (tree[at]>Max)
			Max=tree[at];
		return;
	}
	int mid=(l+r)/2;
	if (dl<=mid)
		query(2*at,l,mid,dl,dr);
	if (dr>=mid+1)
		query(2*at+1,mid+1,r,dl,dr);
}
long long max(long long a,long long b){
	return (a>b)?a:b;
}
void update(int at,int l,int r,int x,long long v){
	if (l==r){
		tree[at]=v;
		return;
	}
	int mid=(l+r)/2;
	if (x<=mid)
		update(2*at,l,mid,x,v);
	if (x>=mid+1)
		update(2*at+1,mid+1,r,x,v);
	tree[at]=max(tree[2*at],tree[2*at+1]);
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
	int n;
	while (scanf("%d",&n)==1){
		for (int i=0;i<n;i++)
			a[i]=input(),p[i]=&a[i];
		std::stable_sort(p,p+n,cmp);
		int f=-1,num=0;
		for (int i=0;i<n;i++){
			if (f!=(*p[i])){
				f=(*p[i]);
				c[num++]=f;
			}
			(*p[i])=num-1;
		}
		long long ans=0;
		init(1,0,num-1);
		for (int i=0;i<n;i++){
			Max=0;
			if (a[i])
				query(1,0,num-1,0,a[i]-1);
			if (Max+c[a[i]]>ans)
				ans=Max+c[a[i]];
			update(1,0,num-1,a[i],Max+c[a[i]]);
		}
		printf("%lld\n",ans);
	}
}
