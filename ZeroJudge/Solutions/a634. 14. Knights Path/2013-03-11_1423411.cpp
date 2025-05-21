#include <cstdio>
#include <cstring>
#include <algorithm>

struct Queue{
	int x,y,d;
} Q[10000];
char st[3],ed[3],tmp[3];
bool map[10][10];
bool in(int x,int y){
	return x>=0&&x<8&&y>=0&&y<8;
}
int v[10][10];
int move[8][2]={{1,2},{-1,2},{1,-2},{-1,-2},{2,1},{-2,1},{2,-1},{-2,-1}};
int num,ans[10000][100][2],now[100][2];
int t[10000];
void dfs(int x,int y,int d){
	now[d][0]=x,now[d][1]=y;
	if (d==0){
		for (int i=0;i<=v[ed[0]][ed[1]];i++)
			ans[num][i][0]=now[i][0],ans[num][i][1]=now[i][1];
		t[num]=num;
		num++;
		return;
	}
	for (int i=0;i<8;i++){
		int xx=x+move[i][0],yy=y+move[i][1];
		if (in(xx,yy)&&v[xx][yy]==d-1&&map[xx][yy])
			dfs(xx,yy,d-1);
	}
}
bool cmp(int i,int j){
	for (int k=0;k<=v[ed[0]][ed[1]];k++){
		if (ans[i][k][0]>ans[j][k][0])
			return false;
		if (ans[i][k][0]<ans[j][k][0])
			return true;
		if (ans[i][k][1]>ans[j][k][1])
			return false;
		if (ans[i][k][1]<ans[j][k][1])
			return true;
	}
	return true;
}
int main()
{
	while (scanf("%s",st)==1){
		scanf("%s",ed);
		ed[0]-='a';
		ed[1]-='1';
		for (int i=0;i<8;i++)
			for (int j=0;j<8;j++)
				map[i][j]=true,v[i][j]=-1;
		while (scanf("%s",tmp),strcmp(tmp,"xx")!=0)
			map[tmp[0]-'a'][tmp[1]-'1']=false;		
		int l=0,r=0;
		Q[r].x=st[0]-'a';
		Q[r].y=st[1]-'1';
		Q[r].d=0;
		r++;
		v[st[0]-'a'][st[1]-'1']=0;
		while (l<r){
			int x=Q[l].x,y=Q[l].y,d=Q[l].d;
			//printf("%d %d\n",x,y);
			l++;
			if (x==ed[0]&&y==ed[1])
				break;
			for (int i=0;i<8;i++){
				int xx=x+move[i][0],yy=y+move[i][1];
				if (in(xx,yy)&&v[xx][yy]==-1&&map[xx][yy]){
					Q[r].x=xx;
					Q[r].y=yy;
					Q[r].d=d+1;
					r++;
					v[xx][yy]=d+1;
				}
			}
		}
		printf("The shortest solution is %d move(s).\n",v[ed[0]][ed[1]]);
		num=0;
		dfs(ed[0],ed[1],v[ed[0]][ed[1]]);
		std::stable_sort(t,t+num,cmp);
		//printf("%d\n",num);
		for (int i=0;i<num;i++){
			printf("Solution:");
			for (int j=0;j<=v[ed[0]][ed[1]];j++)
				printf(" %c%d",ans[t[i]][j][0]+'a',ans[t[i]][j][1]+1);
			puts("");
		}
	}
}
/*
The shortest solution is 3 move(s).
Solution: c6 b4 d3 c5
Solution: c6 d4 e6 c5
Solution: c6 d8 e6 c5
Solution: c6 e5 d3 c5
*/
