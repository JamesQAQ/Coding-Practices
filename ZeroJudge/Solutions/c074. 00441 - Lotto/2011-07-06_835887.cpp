#include <cstdio>

int a[13],ans[6],k;
void dfs(int x,int d){
	if (x==6){
		printf("%d",ans[0]);
		for (int i=1;i<6;i++)
			printf(" %d",ans[i]);
		puts("");
		return;
	}
	for (int i=d;i<k;i++){
		ans[x]=a[i];
		dfs(x+1,i+1);
	}
}
int main()
{
	bool first=true;
	while (scanf("%d",&k)){
		if (k==0)
			break;
		if (first)
			first=false;
		else
			puts("");
		for (int i=0;i<k;i++)
			scanf("%d",&a[i]);
		dfs(0,0);
	}
	return 0;
}
