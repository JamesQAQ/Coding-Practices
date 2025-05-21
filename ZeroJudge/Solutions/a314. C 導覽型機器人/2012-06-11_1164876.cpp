#include <cstdio>

int n,m,a[100][100],stx,sty;
char s[5]={"NSEW"};
int move[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
void work(){
    a[stx][sty]=-1;
    bool found=true;
    int now=-1,cnt;
    while (found){
        found=false;
        for (int i=0;i<4;i++){
            int xx=stx+move[i][0],yy=sty+move[i][1];
            if (xx>=0&&xx<n&&yy>=0&&yy<m)
                if (a[xx][yy]!=-1){
                    a[xx][yy]=-1;
                    stx=xx,sty=yy;
                    found=true;
                    if (now!=i){
                        if (now!=-1)
                            printf("%c%d",s[now],cnt);
                        now=i,cnt=1;
                    }
                    else
                        cnt++;
                }
        }
    }
    printf("%c%d",s[now],cnt);
    puts("");
}
int main()
{
    int cases;
    scanf("%d",&cases);
    while (cases--){
        scanf("%d %d",&n,&m);
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++){
                scanf("%d",&a[i][j]);
                if (a[i][j]==0)
                    stx=i,sty=j;
            }
        work();
    }
}
