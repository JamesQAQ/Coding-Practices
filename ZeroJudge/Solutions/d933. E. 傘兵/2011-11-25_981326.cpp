#include <cstdio>
#include <algorithm>

struct Node {int x,y,v;} node[100],Q[10000];
int l,r,R,C,n,map[102][102],move[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
bool cmp(Node i,Node j){
    return i.v<j.v;
}
int main()
{
    int cases,at;
    scanf("%d",&cases);
    while (cases--){
        scanf("%d %d %d",&R,&C,&n);
        for (int i=1;i<=R;i++)
            for (int j=1;j<=C;j++)
                map[i][j]=-1;
        for (int i=0;i<=R+1;i++)
            map[i][0]=map[i][C+1]=1;
        for (int i=0;i<=C+1;i++)
            map[0][i]=map[R+1][i]=1;
        for (int i=0;i<n;i++)
            scanf("%d %d %d",&node[i].x,&node[i].y,&node[i].v);
        std::stable_sort(node,node+n,cmp);
        at=1,l=0,r=1;
        Q[0]=node[0];
        map[node[0].x][node[0].y]=node[0].v;
        while (l<r){
            int x=Q[l].x,y=Q[l].y,v=Q[l].v;
            l++;
            while (at<n&&v==node[at].v){
                if (map[node[at].x][node[at].y]==-1)
                    map[node[at].x][node[at].y]=v,Q[r++]=node[at];
                at++;
            }
            for (int i=0;i<4;i++){
                int xx=x+move[i][0],yy=y+move[i][1];
                if (map[xx][yy]==-1){
                    map[xx][yy]=v+1;
                    Q[r].x=xx,Q[r].y=yy,Q[r].v=v+1;
                    r++;
                }
            }
        }
        for (int i=1;i<=R;i++){
            for (int j=1;j<=C;j++)
                printf((j-1)?" %d":"%d",map[i][j]);
            puts("");
        }
    }
    return 0;
}
