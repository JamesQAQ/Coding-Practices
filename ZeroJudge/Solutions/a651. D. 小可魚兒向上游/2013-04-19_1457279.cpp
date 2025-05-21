#include <cstdio>
#include <vector>

std::vector <int> path[100000];
int no[100000],mark[100000],sum,dfn[100000],L[100000],R[100000],tree[4000000];
void dfs(int x,int f,int d){
	dfn[x]=d;
	L[x]=sum;
	sum++;
	int p=path[x].size();
	for (int i=0;i<p;i++){
		int to=path[x][i];
		if (to!=f)
			dfs(to,x,d+1);
	}
	R[x]=sum-1;
}
void init(int at,int l,int r){
	tree[at]=-1;
	if (l==r)
		return;
	int mid=(l+r)/2;
	init(2*at,l,mid);
	init(2*at+1,mid+1,r);
}
void update(int at,int l,int r,int dl,int dr,int v){
	//printf("update %d %d %d\n",l,r,v);
	if (dl<=l&&r<=dr){
		if (tree[at]==-1||dfn[tree[at]]<dfn[v])
			tree[at]=v;
		return;
	}
	int mid=(l+r)/2;
	if (dl<=mid)
		update(2*at,l,mid,dl,dr,v);
	if (dr>=mid+1)
		update(2*at+1,mid+1,r,dl,dr,v);
}
int ans;
void query(int at,int l,int r,int x){
	//printf("query %d %d %d %d %d\n",at,l,r,x,tree[at]);
	if (tree[at]!=-1)
		ans=tree[at];
	if (l==r)
		return;
	int mid=(l+r)/2;
	if (x<=mid)
		query(2*at,l,mid,x);
	if (x>=mid+1)
		query(2*at+1,mid+1,r,x);
}
int main()
{
	int cases,tmp,n,m;
	scanf("%d",&cases);
	while (cases--){
		sum=0;
		scanf("%d %d",&n,&m);
		for (int i=0;i<n;i++)
			path[i].clear();
		for (int i=1;i<n;i++){
			scanf("%d",&tmp);
			path[tmp].push_back(i);
			path[i].push_back(tmp);
		}
		dfs(0,-1,0);
		//for (int i=0;i<n;i++)
		//	printf("%d~%d\n",L[i],R[i]);
		init(1,0,n-1);
		update(1,0,n-1,L[0],R[0],0);
		int hash;
		for (int i=0;i<m;i++){
			scanf("%d",&tmp);
			query(1,0,n-1,L[tmp]);
			//printf("%d\n",ans);
			if (i==0)
				hash=ans+i+1;
			else
				hash^=ans+i+1;
			update(1,0,n-1,L[tmp],R[tmp],tmp);
		}
		printf("%d\n",hash);
	}
}
