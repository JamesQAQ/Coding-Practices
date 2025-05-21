#include <cstdio>

char s[101];
bool map[102][102];
int move[8][2]={{0,1},{1,0},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
int cnt(int x,int y){
    int sum=0;
    for (int i=0;i<8;i++)
        sum+=(int)map[x+move[i][0]][y+move[i][1]];
    return sum;
}
int main()
{
    int n,p;
    while (scanf("%d",&n)==1){
        for (int i=0;i<=n+1;i++)
            map[i][0]=map[i][n+1]=map[0][i]=map[n+1][i]=false;
        for (int i=1;i<=n;i++){
            scanf("%s",s);
            for (int j=1;j<=n;j++)
                map[i][j]=(s[j-1]=='*');
        }
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                if (map[i][j])
                    putchar('*');
                else
                    putchar((p=cnt(i,j))?p+'0':'-');
            }
            putchar('\n');
        }
    }
}
