#include <cstdio>

int a[1510][1510]={},sum[1510][1510];
int L[1510]={},R[1510]={},U[1510]={},D[1510]={},DL[1510]={},DR[1510]={},DU[1510]={},DD[1510]={};
int max(int a,int b){
	return (a>b)?a:b;
}
int getsum(int x,int y,int k){
	return sum[x+k-1][y+k-1]-sum[x-1][y+k-1]-sum[x+k-1][y-1]+sum[x-1][y-1];
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
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++){
			a[i][j]=input();
			sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j];
		}
	//single
	for (int i=1;i<=n-k+1;i++)
		for (int j=1;j<=m-k+1;j++){
			int v=getsum(i,j,k);
			L[j+k-1]=max(L[j+k-1],v);
			R[j]=max(R[j],v);
			U[i+k-1]=max(U[i+k-1],v);
			D[i]=max(D[i],v);
		}
	for (int i=1;i<=m;i++)
		L[i]=max(L[i],L[i-1]);
	for (int i=m;i>=1;i--)
		R[i]=max(R[i],R[i+1]);
	for (int i=1;i<=n;i++)
		U[i]=max(U[i],U[i-1]);
	for (int i=1;i<=n;i++)
		D[i]=max(D[i],D[i+1]);
	//double
	//DL
	int deque[1501],b[1501],maxx[1501];
	for (int i=1;i<=n-k+1;i++)
		maxx[i]=0;
	for (int j=1;j<=m-k+1;j++){
		for (int i=1;i<=n-k+1;i++){
			int v=getsum(i,j,k);
			maxx[i]=max(maxx[i],v);
		}
		int l=0,r=0,front=0;
		for (int i=k+1;i<=n-k+1;i++){
			while (l<r&&maxx[i]>deque[r-1])
				r--;
			deque[r]=maxx[i];
			b[r++]=i;
		}
		for (int i=1;i<=n-k+1;i++){
			int v=getsum(i,j,k);
			if (l<r&&b[l]<i+k)
				l++;
			DL[j+k-1]=max(DL[j+k-1],L[j-1]+v);
			DL[j+k-1]=max(DL[j+k-1],front+v);
			if (l<r)
				DL[j+k-1]=max(DL[j+k-1],deque[l]+v);
			if (i-k>=1)
				front=max(front,maxx[i-k]);
		}
	}
	//DR
	for (int i=1;i<=n-k+1;i++)
		maxx[i]=0;
	for (int j=m-k+1;j>=1;j--){
		for (int i=1;i<=n-k+1;i++){
			int v=getsum(i,j,k);
			maxx[i]=max(maxx[i],v);
		}
		int l=0,r=0,front=0;
		for (int i=k+1;i<=n-k+1;i++){
			while (l<r&&maxx[i]>deque[r-1])
				r--;
			deque[r]=maxx[i];
			b[r++]=i;
		}
		for (int i=1;i<=n-k+1;i++){
			int v=getsum(i,j,k);
			if (l<r&&b[l]<i+k)
				l++;
			DR[j]=max(DR[j],R[j+k]+v);
			DR[j]=max(DR[j],front+v);
			if (l<r)
				DR[j]=max(DR[j],deque[l]+v);
			if (i-k>=1)
				front=max(front,maxx[i-k]);
		}
	}
	//DU
	for (int j=1;j<=m-k+1;j++)
		maxx[j]=0;
	for (int i=1;i<=n-k+1;i++){
		for (int j=1;j<=m-k+1;j++){
			int v=getsum(i,j,k);
			maxx[j]=max(maxx[j],v);
		}
		int l=0,r=0,front=0;
		for (int j=k+1;j<=n-k+1;j++){
			while (l<r&&maxx[j]>deque[r-1])
				r--;
			deque[r]=maxx[j];
			b[r++]=j;
		}
		for (int j=1;j<=m-k+1;j++){
			int v=getsum(i,j,k);
			if (l<r&&b[l]<j+k)
				l++;
			DU[i+k-1]=max(DU[i+k-1],U[i-1]+v);
			DU[i+k-1]=max(DU[i+k-1],front+v);
			if (l<r)
				DU[i+k-1]=max(DU[i+k-1],deque[l]+v);
			//printf("%d + %d %d %d %d\n",v,U[i-1],front,deque[l],l<r);
			if (j-k>=1)
				front=max(front,maxx[j-k]);
		}
	}
	//DD
	for (int j=1;j<=m-k+1;j++)
		maxx[j]=0;
	for (int i=n-k+1;i>=1;i--){
		for (int j=1;j<=m-k+1;j++){
			int v=getsum(i,j,k);
			maxx[j]=max(maxx[j],v);
		}
		int l=0,r=0,front=0;
		for (int j=k+1;j<=n-k+1;j++){
			while (l<r&&maxx[j]>deque[r-1])
				r--;
			deque[r]=maxx[j];
			b[r++]=j;
		}
		for (int j=1;j<=m-k+1;j++){
			int v=getsum(i,j,k);
			if (l<r&&b[l]<j+k)
				l++;
			DD[i]=max(DD[i],D[i+k]+v);
			DD[i]=max(DD[i],front+v);
			if (l<r)
				DD[i]=max(DD[i],deque[l]+v);
			if (j-k>=1)
				front=max(front,maxx[j-k]);
		}
	}
	for (int i=1;i<=m;i++)
		DL[i]=max(DL[i],DL[i-1]);
	for (int i=m;i>=1;i--)
		DR[i]=max(DR[i],DR[i+1]);
	for (int i=1;i<=n;i++)
		DU[i]=max(DU[i],DU[i-1]);
	for (int i=n;i>=1;i--)
		DD[i]=max(DD[i],DD[i+1]);
	//all
	int ans=0;
	for (int i=1;i<=n-k+1;i++)
		for (int j=1;j<=m-k+1;j++){
			int v=getsum(i,j,k);
			ans=max(ans,v+DL[j-1]);
			ans=max(ans,v+DR[j+k]);
			ans=max(ans,v+DU[i-1]);
			ans=max(ans,v+DD[i+k]);
			//printf("%d + %d %d %d %d\n",v,DL[j-1],DR[j+k],DU[i-1],DD[i+k]);
		}
	printf("%d\n",ans);
	/*for (int i=1;i<=m;i++)
		printf("%d,%d ",L[i],R[i]);
	puts("");
	for (int i=1;i<=n;i++)
		printf("%d,%d ",U[i],D[i]);
	puts("");
	for (int i=1;i<=m;i++)
		printf("%d,%d ",DL[i],DR[i]);
	puts("");
	for (int i=1;i<=n;i++)
		printf("%d,%d ",DU[i],DD[i]);
	puts("");*/
}
/*
9 9 3
1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1
1 8 8 8 8 8 1 1 1
1 8 8 8 8 8 1 1 1
1 8 8 8 8 8 1 1 1
1 1 1 1 8 8 8 1 1
1 1 1 1 1 1 8 8 8
1 1 1 1 1 1 9 9 9
1 1 1 1 1 1 9 9 9
*/
