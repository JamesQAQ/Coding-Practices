#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>

#include <iostream>

struct Path {int x,y,w;} ;
struct Point {int x,y;long long v;} ;
struct Node {int x[2],y[2];} rec[1010];
struct OAO {int x,i;} t[2020];
std::vector <Path> path;
int map[2020][2020],X[2020],xnum,Y[2020],ynum;
long long dis[2020][2020];
bool cmpx(OAO i,OAO j){
    return rec[i.x].x[i.i]<rec[j.x].x[j.i];
}
bool cmpy(OAO i,OAO j){
    return rec[i.x].y[i.i]<rec[j.x].y[j.i];
}
void clear_node(int x,int y){
    dis[x][y]=-1;
}
void build(int x){
    for (int i=rec[x].x[0];i<=rec[x].x[1];i++){
        map[i][rec[x].y[0]]=map[i][rec[x].y[1]]=x;
        clear_node(i,rec[x].y[0]),clear_node(i,rec[x].y[1]);
    }
    for (int i=rec[x].y[0];i<=rec[x].y[1];i++){
        map[rec[x].x[0]][i]=map[rec[x].x[1]][i]=x;
        clear_node(rec[x].x[0],i),clear_node(rec[x].x[1],i);
    }
    for (int i=rec[x].x[0]+1;i<rec[x].x[1];i++)
        for (int j=rec[x].y[0]+1;j<rec[x].y[1];j++)
            map[i][j]=x;
}
void build_edge(int x,int y){
    path.clear();
    Path tmp;
    int v=map[x][y];
    if (y+1<ynum&&map[x][y+1]!=v){
        int d=1;
        while (y+d<ynum&&map[x][y+d]==-1)
            d++;
        if (y+d<ynum&&map[x][y+d]!=-1){
            tmp.x=x,tmp.y=y+d,tmp.w=Y[y+d]-Y[y];
            path.push_back(tmp);
        }
    }
    else if (y+1<ynum&&(x==rec[v].x[0]||x==rec[v].x[1])){
        tmp.x=x,tmp.y=y+1,tmp.w=Y[y+1]-Y[y];
        path.push_back(tmp);
    }
    if (y-1>=0&&map[x][y-1]!=v){
        int d=1;
        while (y-d>=0&&map[x][y-d]==-1)
            d++;
        if (y-d>=0&&map[x][y-d]!=-1){
            tmp.x=x,tmp.y=y-d,tmp.w=Y[y]-Y[y-d];
            path.push_back(tmp);
        }
    }
    else if (y-1>=0&&(x==rec[v].x[0]||x==rec[v].x[1])){
        tmp.x=x,tmp.y=y-1,tmp.w=Y[y]-Y[y-1];
        path.push_back(tmp);
    }
    if (x+1<xnum&&map[x+1][y]!=v){
        int d=1;
        while (x+d<xnum&&map[x+d][y]==-1)
            d++;
        if (x+d<xnum&&map[x+d][y]!=-1){
            tmp.x=x+d,tmp.y=y,tmp.w=X[x+d]-X[x];
            path.push_back(tmp);
        }
    }
    else if (x+1<xnum&&(y==rec[v].y[0]||y==rec[v].y[1])){
        tmp.x=x+1,tmp.y=y,tmp.w=X[x+1]-X[x];
        path.push_back(tmp);
    }
    if (x-1>=0&&map[x-1][y]!=v){
        int d=1;
        while (x-d>=0&&map[x-d][y]==-1)
            d++;
        if (x-d>=0&&map[x-d][y]!=-1){
            tmp.x=x-d,tmp.y=y,tmp.w=X[x]-X[x-d];
            path.push_back(tmp);
        }
    }
    else if (x-1>=0&&(y==rec[v].y[0]||y==rec[v].y[1])){
        tmp.x=x-1,tmp.y=y,tmp.w=X[x]-X[x-1];
        path.push_back(tmp);
    }
}
struct Heap{
    int num;
    Point a[5000];
    bool empty(){
        return num==0;
    }
    Point front(){
        return a[1];
    }
    void down(int x){
        int s=x<<1;
        while (s<=num){
            if (s<num&&a[s+1].v<a[s].v)
                s++;
            if (a[s].v>=a[x].v)
                break;
            std::swap(a[s],a[x]);
            x=s,s<<=1;
        }
    }
    void pop(){
        a[1]=a[num--];
        down(1);
    }
    void up(int x){
        int f=x>>1;
        while (f>=1&&a[f].v>a[x].v){
            std::swap(a[f],a[x]);
            x=f,f>>=1;
        }
    }
    void push(Point tmp){
        a[++num]=tmp;
        up(num);
    }
} Q;
void spfa(){
    Point tmp;
    int stx=rec[0].x[0],sty=rec[0].y[0];
    dis[stx][sty]=0;
    tmp.x=stx,tmp.y=sty,tmp.v=0;
    Q.num=0;
    Q.push(tmp);
    while (!Q.empty()){
        tmp=Q.front();
        Q.pop();
        int x=tmp.x,y=tmp.y;
        long long v=tmp.v;
        if (v!=dis[x][y])
            continue;
        build_edge(x,y);
        int p=path.size();
        for (int i=0;i<p;i++){
            int xx=path[i].x,yy=path[i].y,w=path[i].w;
            if (dis[xx][yy]==-1||dis[x][y]<dis[xx][yy]-w){
                dis[xx][yy]=dis[x][y]+w;
                tmp.x=xx,tmp.y=yy,tmp.v=dis[xx][yy];
                Q.push(tmp);
            }
        }
    }
}
int main()
{
    int cases,n;
    scanf("%d",&cases);
    while (cases--){
        scanf("%d %d %d %d",&rec[0].x[0],&rec[0].y[0],&rec[0].x[1],&rec[0].y[1]);
        scanf("%d",&n);
        for (int i=1;i<=n;i++){
            scanf("%d %d %d %d",&rec[i].x[0],&rec[i].y[0],&rec[i].x[1],&rec[i].y[1]);
            if (rec[i].x[0]>rec[i].x[1])
                std::swap(rec[i].x[0],rec[i].x[1]);
            if (rec[i].y[0]>rec[i].y[1])
                std::swap(rec[i].y[0],rec[i].y[1]);
        }
        for (int i=0,j=0;i<=n;i++,j+=2){
            t[j].x=i,t[j].i=0;
            t[j+1].x=i,t[j+1].i=1;
        }
        std::stable_sort(t,t+2*(n+1),cmpx);
        int f=rec[t[0].x].x[t[0].i];xnum=1;
        X[0]=f,rec[t[0].x].x[t[0].i]=0;
        for (int i=1;i<2*(n+1);i++){
            int *p=&rec[t[i].x].x[t[i].i];
            if (f!=(*p)){
                f=(*p);
                X[xnum]=f;
                xnum++;
            }
            (*p)=xnum-1;
        }
        for (int i=0,j=0;i<=n;i++,j+=2){
            t[j].x=i,t[j].i=0;
            t[j+1].x=i,t[j+1].i=1;
        }
        std::stable_sort(t,t+2*(n+1),cmpy);
        f=rec[t[0].x].y[t[0].i];ynum=1;
        Y[0]=f,rec[t[0].x].y[t[0].i]=0;
        for (int i=1;i<2*(n+1);i++){
            int *p=&rec[t[i].x].y[t[i].i];
            if (f!=(*p)){
                f=(*p);
                Y[ynum]=f;
                ynum++;
            }
            (*p)=ynum-1;
        }
        for (int i=0;i<xnum;i++)
            for (int j=0;j<ynum;j++)
                map[i][j]=-1;
        for (int i=1;i<=n;i++)
            build(i);
        map[rec[0].x[0]][rec[0].y[0]]=21;map[rec[0].x[1]][rec[0].y[1]]=0;
        clear_node(rec[0].x[0],rec[0].y[0]),clear_node(rec[0].x[1],rec[0].y[1]);
        spfa();
        (dis[rec[0].x[1]][rec[0].y[1]]==-1)?puts("No Path"):printf("%lld\n",dis[rec[0].x[1]][rec[0].y[1]]);
    }
}
