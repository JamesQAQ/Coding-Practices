#include <cstdio>

bool in(int x,int y){
	return x>=0&&x<=99&&y>=0&&y<=99;
}
char map[100][100];
void init(){
	for (int i=0;i<=99;i++)
		for (int j=0;j<=99;j++)
			map[i][j]='.';
}
struct Queue{
	int x,y,d;
} Q[10000];
int move[8][2]={{1,3},{-1,3},{1,-3},{-1,-3},{3,1},{3,-1},{-3,1},{-3,-1}},go[8][2]={{0,1},{0,1},{0,-1},{0,-1},{1,0},{1,0},{-1,0},{-1,0}};
int main()
{
	int n,sx,sy,x,y;
	while (scanf("%d",&n)==1){
		init();
		for (int i=0;i<n;i++){
			scanf("%d %d",&x,&y);
			map[x][y]='#';
		}
		scanf("%d %d",&x,&y);
		map[x][y]='S';
		sx=x,sy=y;
		scanf("%d %d",&x,&y);
		map[x][y]='E';
		int l=0,r=0,ans=-1;
		Q[r].x=sx,Q[r].y=sy,Q[r].d=0;
		r++;
		map[sx][sy]='*';
		while (l<r){
			int tx=Q[l].x,ty=Q[l].y,td=Q[l].d;
			l++;
			//printf("%d %d %d\n",tx,ty,td);
			//getchar();
			for (int i=0;i<8;i++){
				int xx=tx+move[i][0],yy=ty+move[i][1];
					//printf("xx %d yy %d  %c %c\n",xx,yy,map[tx+go[i][0]][ty+go[i][1]],map[xx][yy]);
				if (in(xx,yy)&&map[tx+go[i][0]][ty+go[i][1]]!='#'){
					if (map[xx][yy]=='.'){
						map[xx][yy]='*';
						Q[r].x=xx,Q[r].y=yy,Q[r].d=td+1;
						r++;
					}
					else if (map[xx][yy]=='E'){
						
						ans=td+1;
						break;
					}
				}
				if (ans!=-1)
					break;
			}
			if (ans!=-1)
				break;
		}
		if (ans==-1)
			puts("impossible");
		else
			printf("%d\n",ans);
	}
}

/*
4
3 6
4 5
5 4
6 3
3 3
7 5
2
1 1
0 2
0 1
4 3
*/
