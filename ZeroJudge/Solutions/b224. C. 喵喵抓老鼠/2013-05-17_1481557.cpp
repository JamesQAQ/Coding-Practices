#include <cstdio>
#include <cstring>

char map[100][101];
struct Node{
	int x,y,d;
} Q[10000];
int move[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int main()
{
	int n,m;
	while (scanf("%d",&n),n){
		for (int i=0;i<n;i++)
			scanf("%s",map[i]);
		m=strlen(map[0]);
		int l=0,r=0;
		int ans=-1;
		for (int i=0;i<n;i++)
			for (int j=0;j<m;j++)
				if (map[i][j]=='K'){
					Q[r].x=i,Q[r].y=j,r++;
					while (l<r){
						int x=Q[l].x,y=Q[l].y,d=Q[l].d;
						l++;
						for (int k=0;k<4;k++){
							int xx=x+move[k][0],yy=y+move[k][1];
							if (map[xx][yy]=='.'){
								Q[r].x=xx,Q[r].y=yy,Q[r].d=d+1,r++;
								map[xx][yy]='#';
							}
							else if (map[xx][yy]=='@'){
								ans=d+1;
								break;
							}
						}
						if (ans!=-1)
							break;
					}
					break;
				}
		if (ans==-1)
			puts("= =\"");
		else
			printf("%d\n",ans);
	}
}
