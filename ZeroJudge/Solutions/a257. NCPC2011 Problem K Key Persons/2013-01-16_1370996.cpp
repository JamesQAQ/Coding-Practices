#include <cstdio>
#include <vector>

int n,a[1000],dfn[1000],low[1000];
bool ap[1000],v[1000];
std::vector <int> path[1000];
int gcd(int m,int n){
	while ((m%=n)&&(n%=m));
	return (m==0)?n:m;
}
int min(int a,int b){
	return (a<b)?a:b;
}
void dfs(int x,int f,int d){
	v[x]=true;
	dfn[x]=low[x]=d;
	int cnt=0,p=path[x].size();
	for (int j=0;j<p;j++){
		int i=path[x][j];
		if (gcd(a[x],a[i])>1){
			if (v[i])
				low[x]=min(low[x],dfn[i]);
			else{
				dfs(i,x,d+1);
				cnt++;
				low[x]=min(low[x],low[i]);
				if ((d==0&&cnt>1)||(d!=0&&low[i]>=dfn[x]))
					ap[x]=true;
			}
		}
	}
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
		n=input();
		for (int i=0;i<n;i++){
			a[i]=input();
			v[i]=ap[i]=false;
			path[i].clear();
		}
		for (int i=0;i<n;i++)
			for (int j=i+1;j<n;j++)
				if (gcd(a[i],a[j])>1)
					path[i].push_back(j),path[j].push_back(i);
		for (int i=0;i<n;i++)
			if (!v[i])
				dfs(i,-1,0);
		int ans=0;
		for (int i=0;i<n;i++)
			if (ap[i])
				ans++;
		printf("%d\n",ans);
	}	
}
