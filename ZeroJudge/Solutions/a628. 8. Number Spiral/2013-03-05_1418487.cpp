#include <cstdio>

int a[20][20];
int move[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int main()
{
	int n;
	while (scanf("%d",&n)==1){
		int x=n/2,y=n/2,d=0;
		for (int i=0;i<n;i++)
			for (int j=0;j<n;j++)
				a[i][j]=-1;
		for (int i=0;i<n*n;i++){
			a[x][y]=i;
			if (a[x+move[(d+1)%4][0]][y+move[(d+1)%4][1]]==-1)
				d=(d+1)%4;
			x+=move[d][0],y+=move[d][1];
		}
		for (int i=0;i<n;i++){
			for (int j=0;j<n;j++)
				printf("%4d",a[i][j]);
			puts("");
		}
	}
}
