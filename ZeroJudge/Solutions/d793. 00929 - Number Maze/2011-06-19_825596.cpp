#include <cstdio>

struct Node {int x,y;};
int map[1000][1000],d[1000][1000],move[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
struct Heap{
    int num;
    Node at[1000000];
    void change(int a,int b){
        Node te;
        te=at[a];at[a]=at[b];at[b]=te;
    }
    void down(int x){
        int s=x<<1;
        while (s<=num){
            if (s<num&&d[at[s].x][at[s].y]>d[at[s+1].x][at[s+1].y])
                s++;
            if (d[at[s].x][at[s].y]>=d[at[x].x][at[x].y])
                break;
            change(s,x);
            x=s;
            s<<=1;
        }
    }
    void up(int x){
        int f=x>>1;
        while (f>=1&&d[at[f].x][at[f].y]>d[at[x].x][at[x].y]){
            change(f,x);
            x=f;
            f>>=1;
        }
    }
    void pop(){
        at[1]=at[num];
        num--;
        down(1);
    }
    void update(int x){
        up(x);
        down(x);
    }
    void insert(int x,int y){
        at[++num].x=x,at[num].y=y;
        update(num);
    }
}heap;
int input(){
    char c=getchar();
    while (c==' '||c=='\n')
        c=getchar();
    int x=c-48;
    c=getchar();
    while (c!=' '&&c!='\n'){
        x=x*10+c-48;
        c=getchar();
    }
    return x;
}
int main()
{
    int cases,n,m;
    cases=input();
    while (cases--){
        n=input();m=input();
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                map[i][j]=input(),d[i][j]=2147483647;
        d[0][0]=map[0][0];
        heap.num=1;
        heap.at[1].x=heap.at[1].y=0;
        while (heap.num>0){
            int x=heap.at[1].x,y=heap.at[1].y;
            heap.pop();
            if (x==n-1&&y==m-1)
                break;
            for (int i=0;i<4;i++){
                int xx=x+move[i][0],yy=y+move[i][1];
                if (xx>=0&&xx<n&&yy>=0&&y<m)
                    if (d[x][y]+map[xx][yy]<d[xx][yy]){
                        d[xx][yy]=d[x][y]+map[xx][yy];
                        heap.insert(xx,yy);
                    }
            }
        }
        printf("%d\n",d[n-1][m-1]);
    }
    return 0;
}
