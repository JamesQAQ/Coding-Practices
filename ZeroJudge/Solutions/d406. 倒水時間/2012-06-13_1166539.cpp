#include <cstdio>

int map[102][102],s;
struct Node {int x,y,d;} Q[10000],tmp;
bool visit[102][102];
int move[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
int main()
{
    int n,m,cases=0;
    while (scanf("%d",&s)==1){
        scanf("%d %d",&n,&m);
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                scanf("%d",&map[i][j]),visit[i][j]=false;
        for (int i=0;i<=m+1;i++)
            map[0][i]=map[n+1][i]=0;
        for (int i=0;i<=n+1;i++)
            map[i][0]=map[i][m+1]=0;
        tmp.x=1;
        for (int i=1;i<=m;i++)
            if (map[1][i]){
                tmp.y=i;
                break;
            }
        tmp.d=1;
        Q[0]=tmp;
        visit[tmp.x][tmp.y]=true;
        int l=0,r=1;
        while (l<r){
            int x=Q[l].x,y=Q[l].y,d=Q[l].d;
            l++;
            for (int i=s-1;i<4;i++){
                int xx=move[i][0]+x,yy=y+move[i][1];
                if (map[xx][yy]==1&&!visit[xx][yy]){
                    visit[xx][yy]=true;
                    map[xx][yy]=d+1;
                    Q[r].x=xx,Q[r].y=yy,Q[r].d=d+1;
                    r++;
                }
            }
        }
        printf("Case %d:\n",++cases);
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++)
                printf((j-1==0)?"%d":" %d",(visit[i][j])?map[i][j]:0);
            puts("");
        }
    }
}
