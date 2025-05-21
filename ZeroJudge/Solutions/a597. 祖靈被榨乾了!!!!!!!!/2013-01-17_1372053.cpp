#include <cstdio>

char map[500][501];
int m,n;
bool in(int x,int y){
	return x>=0&&y>=0&&x<m&&y<n;
}
struct Queue{
	int x,y;
} Q[250000];
int move[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int main()
{
	while (scanf("%d %d",&m,&n)==2){
		gets(map[0]);
		for (int i=0;i<m;i++)
			gets(map[i]);
		int cnt=0,max=0;
		for (int i=0;i<m;i++)
			for (int j=0;j<n;j++)
				if (map[i][j]=='J'){
					cnt++;
					int sum=1,l=0,r=0;
					Q[r].x=i,Q[r].y=j;
					r++;
					map[i][j]='X';
					while (l<r){
						int x=Q[l].x,y=Q[l].y;
						l++;
						for (int k=0;k<4;k++){
							int xx=x+move[k][0],yy=y+move[k][1];
							if (!in(xx,yy))
								continue;
							if (map[xx][yy]=='J'){
								map[xx][yy]='X';
								Q[r].x=xx,Q[r].y=yy;
								r++;
								sum++;
							}
						}
					}
					if (sum>max)
						max=sum;
				}
		printf("%d %d\n",cnt,max);
	}
}
/*
5 5
XXXXX
XXJJX
XJJJX
XXXXX
XJXXX
*/
