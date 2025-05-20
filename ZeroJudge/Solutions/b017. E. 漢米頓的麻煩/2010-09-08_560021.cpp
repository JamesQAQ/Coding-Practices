#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int n,p[101][101];
	while (scanf("%d",&n)!=EOF)
	{
		if (n==0)
			break;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				scanf("%d",&p[j][i]);
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				if (p[i][j]==0)
					p[i][j]=999999;
		for (int x=1;x<=n;x++)
			for (int y=1;y<=n;y++)
				for (int z=1;z<=n;z++)
					p[y][z]=min(p[y][z],p[y][x]+p[x][z]);
		int mini=999999;
		for (int i=1;i<=n;i++)
		    mini=min(p[i][i],mini);
		mini=(mini>=999999)?-1:mini;
		printf("%d\n",mini);
	}
   //system("pause");
   return 0;
}
