#include <iostream>
#include <stdio.h>
using namespace std;

int c[26][30001];
int main()
{
	int n,m,v[26],p[26];
	while (scanf("%d",&n)==1)
	{
		scanf("%d",&m);
		for (int i=1;i<=m;i++)
			scanf("%d %d",&v[i],&p[i]);
		memset(c,0,sizeof(c));
		for (int i=1;i<=m;i++)
			for (int j=1;j<=n;j++)
			{
				if (v[i]<=j)
				{
					if (p[i]*v[i]+c[i-1][j-v[i]]>c[i-1][j])
						c[i][j]=p[i]*v[i]+c[i-1][j-v[i]];
					else
						c[i][j]=c[i-1][j];
				}
				else
					c[i][j]=c[i-1][j];
			}
		printf("%d\n",c[m][n]);
	}
	return 0;
}
