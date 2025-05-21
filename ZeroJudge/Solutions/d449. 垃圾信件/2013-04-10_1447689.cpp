#include <cstdio>

int no[10001],boss[2000000];
bool visit[2000000];
int num;
int find(int x){
	return (boss[x]==x)?x:boss[x]=find(boss[x]);
}
int main()
{
	int n,m;
	while (scanf("%d %d",&n,&m)==2){
		num=n+1;
		for (int i=1;i<=n;i++)
			boss[i]=i,no[i]=i;
		int x,y,tmp;
		while (m--){
			scanf("%d",&tmp);
			if (tmp==1){
				scanf("%d %d",&x,&y);
				x=no[x];
				y=no[y];
				if (find(x)!=find(y))
					boss[find(y)]=find(x);
			}
			else{
				scanf("%d",&x);
				no[x]=num++;
				boss[no[x]]=no[x];
			}
		}
		for (int i=0;i<=num;i++)
			visit[i]=false;
		int ans=0;
		for (int i=1;i<=n;i++)
			if (!visit[find(no[i])]){
				visit[find(no[i])]=true;
				ans++;
			}
		printf("%d\n",ans);
	}
}
