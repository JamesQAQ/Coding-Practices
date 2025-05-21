#include <cstdio>

int n,m,q,a[500][500],maxx,x1,y1,x2,y2;;
struct Node {int t[2000];} tree[2000];
void build(Node &T,int x,int at,int l,int r){
	if (l==r){
		T.t[at]=a[l][x];
		return;
	}
	int mid=(l+r)/2;
	build(T,x,2*at,l,mid);
	build(T,x,2*at+1,mid+1,r);
	T.t[at]=(T.t[2*at]>T.t[2*at+1])?T.t[2*at]:T.t[2*at+1];
}
void combin(int x,int at,int l,int r){
	tree[x].t[at]=(tree[2*x].t[at]>tree[2*x+1].t[at])?tree[2*x].t[at]:tree[2*x+1].t[at];
	if (l==r)
		return;
	int mid=(l+r)/2;
	combin(x,2*at,l,mid);
	combin(x,2*at+1,mid+1,r);
}
void Build(int at,int l,int r){
	if (l==r){
		build(tree[at],l,1,0,n-1);
		return;
	}
	int mid=(l+r)/2;
	Build(2*at,l,mid);
	Build(2*at+1,mid+1,r);
	combin(at,1,0,n-1);
}
void search(Node &T,int at,int l,int r){
	if (l>=x1&&r<=x2){
		
		if (T.t[at]>maxx)
			maxx=T.t[at];
		return;
	}
	int mid=(l+r)/2;
	if (mid>=x1)
		search(T,2*at,l,mid);
	if (mid+1<=x2)
		search(T,2*at+1,mid+1,r);
}
void Search(int at,int l,int r){
	if (l>=y1&&r<=y2){
		search(tree[at],1,0,n-1);
		return;
	}
	int mid=(l+r)/2;
	if (mid>=y1)
		Search(2*at,l,mid);
	if (mid+1<=y2)
		Search(2*at+1,mid+1,r);
}
int main()
{
	scanf("%d %d",&n,&m);
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
			scanf("%d",&a[i][j]);
	Build(1,0,m-1);
	scanf("%d",&q);
	for (int i=0;i<q;i++){
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		x1--,y1--,x2--,y2--;
		maxx=0;
		Search(1,0,m-1);
		printf("%d\n",maxx);
	}
	return 0;
}
