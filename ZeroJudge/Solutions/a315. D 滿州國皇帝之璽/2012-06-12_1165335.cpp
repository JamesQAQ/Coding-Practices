#include <cstdio>

char map[4][20][20],ans[20][20];
void build(int m){
    for (int i=0;i<m;i++){
        for (int j=0;j<m;j++)
            map[1][j][m-i-1]=map[2][m-i-1][m-j-1]=map[3][m-j-1][i]=map[0][i][j];
        map[1][i][m]=map[2][i][m]=map[3][i][m]=0;
    }
}
void insert(int x,int y,int m,int d,int n){
    for (int i=0;i<m;i++)
        for (int j=0;j<m;j++){
            int xx=x+i,yy=y+j;
            if (xx>=0&&xx<n&&yy>=0&&yy<n)
                if (map[d][i][j]=='#')
                    ans[xx][yy]='#';
        }
}
int main()
{
    int cases,n,m,k,x,y,d;
    scanf("%d",&cases);
    while (cases--){
        scanf("%d %d %d",&n,&m,&k);
        for (int i=0;i<m;i++)
            scanf("%s",map[0][i]);
        build(m);
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                ans[i][j]='.';
        for (int i=0;i<k;i++){
            scanf("%d %d %d",&x,&y,&d);
            insert(x,y,m,d,n);
        }
        for (int i=0;i<n;i++)
            ans[i][n]=0,puts(ans[i]);
    }
}
