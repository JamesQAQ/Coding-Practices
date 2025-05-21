#include <cstdio>

char tetris[5][2][5]={{"*   ","*** "},{"    ","****"},{"  * ","*** "},{"**  ","**  "},{"*** "," *  "}};
int n,cnt[5],ans[10],sum;
void dfs(int x){
	if (x==n){
		for (int i=0;i<2;i++){
			for (int j=0;j<n;j++)
				printf("%s|",tetris[ans[j]][i]);
			puts("");
		}
		sum++;
		puts("\n");
		return;
	}
	for (int i=0;i<5;i++)
		if (cnt[i]&&(x==0||ans[x-1]!=i)){
			ans[x]=i;
			cnt[i]--;
			dfs(x+1);
			cnt[i]++;
		}
}
int main()
{
	int m;
	while (scanf("%d %d",&n,&m)==2){
		for (int i=0;i<5;i++)
			cnt[i]=m;
		sum=0;
		dfs(0);
		printf("Sum : %d\n",sum);
	}
}
/*
*000|0000|00*0|**00|***0|
***0|****|***0|**00|0*00|
*/
