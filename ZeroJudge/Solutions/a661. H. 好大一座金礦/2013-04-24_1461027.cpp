#include <cstdio>

bool block[100][100][100];
int main()
{
	int cases,l,w,h;
	char tmp;
	scanf("%d",&cases);
	while (cases--){
		scanf("%d %d %d",&l,&w,&h);
		for (int i=0;i<l;i++)
			for (int j=0;j<w;j++)
				for (int k=0;k<h;k++)
					block[i][j][k]=true;
		for (int i=0;i<w;i++)
			for (int j=0;j<l;j++){
				scanf(" %c",&tmp);
				if (tmp=='.'){
					for (int k=0;k<h;k++)
						block[j][i][k]=false;
				}
			}
		for (int i=0;i<h;i++)
			for (int j=0;j<w;j++){
				scanf(" %c",&tmp);
				if (tmp=='.'){
					for (int k=0;k<l;k++)
						block[k][j][i]=false;
				}
			}
		for (int i=0;i<h;i++)
			for (int j=0;j<l;j++){
				scanf(" %c",&tmp);
				if (tmp=='.'){
					for (int k=0;k<w;k++)
						block[j][k][i]=false;
				}
			}
		int ans=0;
		for (int i=0;i<l;i++)
			for (int j=0;j<w;j++)
				for (int k=0;k<h;k++)
					if (block[i][j][k])
						ans++;
		printf("%d\n",ans);
	}
}
