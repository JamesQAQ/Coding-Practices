#include <iostream>
#include <stdio.h>
using namespace std;

int t,p[101][101],n,m,a,b;
int main()
{
	while (scanf("%d",&t)==1)
	{
		for (int i=0;i<t;i++)
		{
			scanf("%d%d",&n,&m);
			for (int x=1;x<=n;x++)
				for (int y=1;y<=n;y++)
					p[x][y]=201;
			for (int x=0;x<m;x++)
			{
				scanf("%d%d",&a,&b);
				scanf("%d",&p[a][b]);
				p[b][a]=p[a][b];
			}
			for (int x=1;x<=n;x++)
				for (int y=1;y<=n;y++)
					for (int z=1;z<=n;z++)
						p[y][z]=min(p[y][z],max(p[y][x],p[x][z]));
			printf("%d\n",p[1][n]);
		}
	}
   //system("pause");
   return 0;
}
