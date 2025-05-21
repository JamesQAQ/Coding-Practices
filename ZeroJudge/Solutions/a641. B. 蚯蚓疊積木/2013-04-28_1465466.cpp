#include <cstdio>

int hash(int numbers[],int size){
    int value=0,i;
    for(i=0;i<size;i++)
        value^=(numbers[i]+i+1);
    return value;
}
int a[200000],L[1000000],R[1000000];
int max(int a,int b){
	return (a>b)?a:b;
}
void init(int at,int l,int r,int tree[]){
	tree[at]=0;
	if (l==r)
		return;
	int mid=(l+r)/2;
	init(2*at,l,mid,tree);
	init(2*at+1,mid+1,r,tree);
}
void update(int at,int l,int r,int x,int v,int tree[]){
	//printf("update %d %d %d\n",at,l,r);
	if (l==r){
		tree[at]=v;
		return;
	}
	int mid=(l+r)/2;
	if (x<=mid)
		update(2*at,l,mid,x,v,tree);
	else
		update(2*at+1,mid+1,r,x,v,tree);
	tree[at]=max(tree[2*at],tree[2*at+1]);
}
int maxx;
void query(int at,int l,int r,int dl,int dr,int tree[]){
	//printf("query %d %d %d\n",at,l,r);
	if (dl<=l&&r<=dr){
		if (tree[at]>maxx)
			maxx=tree[at];
		return;
	}
	int mid=(l+r)/2;
	if (dl<=mid)
		query(2*at,l,mid,dl,dr,tree);
	if (dr>=mid+1)
		query(2*at+1,mid+1,r,dl,dr,tree);
}
int left[200000],righ[200000];
int cnt[200000],no[200000];
int ans[200000],ansnum;
int main()
{
	int cases,n;
	scanf("%d",&cases);
	while (cases--){
		scanf("%d",&n);
		for (int i=0;i<n;i++)
			scanf("%d",&a[i]);
		int LIS=0;
		init(1,1,n,L);
		for (int i=0;i<n;i++){
			maxx=0;
			if (a[i]>1)
				query(1,1,n,1,a[i]-1,L);
			update(1,1,n,a[i],maxx+1,L);
			left[i]=maxx;
			if (maxx+1>LIS)
				LIS=maxx+1;
		}
		init(1,1,n,R);
		for (int i=n-1;i>=0;i--){
			maxx=0;
			if (a[i]<n)
				query(1,1,n,a[i]+1,n,R);
			update(1,1,n,a[i],maxx+1,R);
			righ[i]=maxx;
		}
		for (int i=0;i<n;i++){
			cnt[i]=0;
			no[i]=0;
		}
		for (int i=0;i<n;i++)
			if (left[i]+righ[i]+1==LIS){
				cnt[left[i]]++;
				no[left[i]]=i+1;
			}
		ansnum=0;
		for (int i=0;i<n;i++)
			if (cnt[i]==1)
				ans[ansnum++]=no[i];
		//printf("LIS %d\n",LIS);
		printf("%d %d\n",ansnum,hash(ans,ansnum));
	}
}
