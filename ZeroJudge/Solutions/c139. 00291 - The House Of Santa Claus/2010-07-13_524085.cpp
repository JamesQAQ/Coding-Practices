#include <iostream>
#include <stdio.h>
using namespace std;

bool p[5][5]={{0,1,1,0,1},{1,0,1,0,1},{1,1,0,1,1},{0,0,1,0,1},{1,1,1,1,0}};
int ans[9];
void dfs(int k,int d,int n)
{
	if (k==9)
	{
		for (int i=0;i<9;i++)
			printf("%d",ans[i]);
		printf("\n");
		return;
	}
	for (int i=0;i<5;i++)
		if (p[d][i])
		{
			ans[n]=i+1;
			p[d][i]=0;
			p[i][d]=0;
			dfs(k+1,i,n+1);
			p[d][i]=1;
			p[i][d]=1;
		}
	return;
}

int main ()
{
	ans[0]=1;
	dfs(1,0,1);
	//system("pause");
	return 0;
}
