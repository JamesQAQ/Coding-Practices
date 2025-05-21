#include <cstdio>

struct Node {int x,y;} e[81];
char map[9][10];
long long C[82][82]={},ans;
int n,m,B,all,move[8][2]={{0,1},{1,0},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}},bomb[9][9],sum[9][9],num;
void print_map(){////////////////////////
    for (int i=0;i<n;i++)
        printf("%s\n",map[i]);
    puts("");
    getchar();
}////////////////////
void count_C(){
    C[0][0]=1;
    for (int i=1;i<=81;i++){
        C[i][0]=C[i][i]=1;
        int d=i/2;
        for (int j=1;j<=d;j++){
            C[i][j]=C[i][j-1]*(i-j+1)/j;
            C[i][i-j]=C[i][j];
        }
    }
}
void cnt_num(int x,int y){
    bomb[x][y]=sum[x][y]=0;
    for (int i=0;i<8;i++){
        int xx=x+move[i][0],yy=y+move[i][1];
        if (xx<0|xx>=n||yy<0||yy>=m)
            continue;
        if (map[xx][yy]=='_')
            sum[x][y]++;
    }
}
void plus(int x,int y,int d,int dd){
    for (int i=0;i<8;i++){
        int xx=x+move[i][0],yy=y+move[i][1];
        if (xx<0|xx>=n||yy<0||yy>=m)
            continue;
        if (map[xx][yy]<='9'&&map[xx][yy]>='0')
            sum[xx][yy]-=d,bomb[xx][yy]+=dd;
    }
}
bool legal(int x,int y){
    for (int i=0;i<8;i++){
        int xx=x+move[i][0],yy=y+move[i][1];
        if (xx<0|xx>=n||yy<0||yy>=m)
            continue;
        if (map[xx][yy]<='9'&&map[xx][yy]>='0'){
            if (bomb[xx][yy]>map[xx][yy]-48)
                return false;
            if (bomb[xx][yy]+sum[xx][yy]<map[xx][yy]-48)
                return false;
        }
    }
    return true;
}
bool found(int x,int y){
    for (int i=0;i<8;i++){
        int xx=x+move[i][0],yy=y+move[i][1];
        if (xx<0|xx>=n||yy<0||yy>=m)
            continue;
        if (map[xx][yy]<='9'&&map[xx][yy]>='0')
            return true;
    }
    return false;
}
void dfs(int X,int bnum){
    //printf("%d %d\n",X,bnum);
    //print_map();
    if (X==num){
        ans+=C[all-num][B-bnum];
        return;
    }
    int x=e[X].x,y=e[X].y;
    if (bnum<B){
        map[x][y]='*';
        plus(x,y,1,1);
        if (legal(x,y))
            dfs(X+1,bnum+1);
        plus(x,y,-1,-1);
        map[x][y]='_';
    }
    if (all-X>B-bnum){
        map[x][y]=' ';
        plus(x,y,1,0);
        if (legal(x,y))
            dfs(X+1,bnum);
        plus(x,y,-1,0);
        map[x][y]='_';
    }
}
int main()
{
    count_C();
    int cases;
    scanf("%d",&cases);
    while (cases--){
        all=num=0;
        scanf("%d %d %d",&n,&m,&B);
        for (int i=0;i<n;i++)
            scanf("%s",map[i]);
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++){
                if (map[i][j]=='_'){
                    all++;
                    if (found(i,j))
                        e[num].x=i,e[num++].y=j;
                }
                else
                    cnt_num(i,j);
            }
        ans=0;
        dfs(0,0);
        printf("%lld\n",ans);
    }
    return 0;
}
