#include <cstdio>

bool map[1002][1002];
int d[1002][1002],h[1002][1002],o[1002][1002],at[1002][1002],boss[1100000];
int find(int x){
    return (x==boss[x])?x:boss[x]=find(boss[x]);
}
int Abs(int x){
    return (x<0)?-x:x;
}
int dis(int ax,int ay,int bx,int by){
    return Abs(ax-bx)+Abs(ay-by);
}
void swap(int &x,int &y){
    x^=y^=x^=y;
}
struct Heap{
    int num,x[1000001],y[1000001];
    void init(){
        num=0;
    }
    void change(int i,int j){
        swap(x[i],x[j]);
        swap(y[i],y[j]);
        swap(at[x[i]][y[i]],at[x[j]][y[j]]);
    }
    bool cmp(int i,int j){
        int A=d[x[i]][y[i]]+h[x[i]][y[i]],B=d[x[j]][y[j]]+h[x[j]][y[j]];
        return A<B;
    }
    void up(int x){
        int f=x>>1;
        while (f>=1&&cmp(x,f)){
            change(x,f);
            x=f,f>>=1;
        }
    }
    void down(int x){
        int s=x<<1;
        while (s<=num){
            if (s<num&&cmp(s+1,s))
                s++;
            if (cmp(x,s))
                break;
            change(s,x);
            x=s,s<<=1;
        }
    }
    void insert(int X,int Y){
        num++;
        x[num]=X,y[num]=Y;
        at[X][Y]=num;
        up(num);
    }
    void pop(){
        change(1,num);
        at[x[num]][y[num]]=-1;
        num--;
        down(1);
    }
} heap;
int move[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
void buildset(int n){
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++){
            int now=i*n+j;
            boss[now]=now;
        }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            if (map[i][j]){
                int now=i*n+j;
                for (int k=0;k<4;k++){
                    int xx=i+move[k][0],yy=j+move[k][1];
                    if (map[xx][yy])
                        boss[find(xx*n+yy)]=find(now);
                }
            }
}
void work(int t,int n){
    int stx,sty,edx,edy;
    scanf("%d %d %d %d",&stx,&sty,&edx,&edy);
    stx++,sty++,edx++,edy++;
    if ((!map[stx][sty])||(!map[edx][edy])){
        puts("ERROR");
        return;
    }
    if (find(stx*n+sty)!=find(edx*n+edy)){
        puts("-1");
        return;
    }
    o[stx][sty]=t;
    d[stx][sty]=0;
    h[stx][sty]=dis(stx,sty,edx,edy);
    heap.init();
    heap.insert(stx,sty);
    int cut=-1;
    bool start=false;
    while (heap.num){
        int x=heap.x[1],y=heap.y[1];
        if (x==edx&&y==edy)
            break;
        if (x-1==24&&y-1==26)
            start=true;
        heap.pop();
        if (cut!=-1&&d[x][y]+h[x][y]>=cut)
            continue;
        for (int i=0;i<4;i++){
            int xx=x+move[i][0],yy=y+move[i][1];
            if (map[xx][yy]){
                if (xx==edx&&yy==edy)
                    if (cut==-1||d[x][y]+1<cut)
                        cut=d[x][y]+1;
                if (o[xx][yy]!=t){
                    o[xx][yy]=t;
                    d[xx][yy]=d[x][y]+1;
                    h[xx][yy]=dis(xx,yy,edx,edy);
                    heap.insert(xx,yy);
                }
                else if (d[x][y]+1<d[xx][yy]){
                    d[xx][yy]=d[x][y]+1;
                    if (at[xx][yy]==-1)
                        heap.insert(xx,yy);
                    else
                        heap.up(at[xx][yy]);
                }
            }
        }
    }
    printf("%d\n",cut);
}
int main()
{
    int n,m;
    char s[1001];
    scanf("%d %d",&n,&m);
    for (int i=0;i<=n+1;i++)
        map[i][0]=map[i][n+1]=map[0][i]=map[n+1][i]=false;
    for (int i=1;i<=n;i++){
        scanf("%s",s);
        for (int j=1;j<=n;j++)
            map[i][j]=(s[j-1]=='.');
    }
    buildset(n);
    for (int i=1;i<=m;i++)
        work(i,n);
}
