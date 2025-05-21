#include <cstdio>

int a[16];
int Abs(int x){
    return (x<0)?-x:x;
}
int cntH(int x){
    int to=a[x]-1;
    return Abs(x%4-to%4)+Abs(x/4-to/4);
}
int st;
bool fail(){
    int sum=0;
    for (int i=0;i<16;i++){
        if (a[i]){
            for (int j=0;j<i;j++)
                if (a[j]&&a[j]>a[i])
                    sum++;
        }
        else
            st=i;
    }
    sum+=st/4;
    return !(sum&1);
}
int limit,move[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
inline bool in(int x,int y){
    return x>=0&&x<4&&y>=0&&y<4;
}
int swap(int &i,int &j){
    i^=j^=i^=j;
}
bool dfs(int d,int x,int y,int H){
    if (d+H>limit)
        return false;
    if (H==0)
        return true;
    for (int i=0;i<4;i++){
        int xx=x+move[i][0],yy=y+move[i][1];
        if (in(xx,yy)){
            H-=cntH(xx*4+yy);
            swap(a[xx*4+yy],a[x*4+y]);
            H+=cntH(x*4+y);
            if (dfs(d+1,xx,yy,H))
                return true;
            H-=cntH(x*4+y);
            swap(a[xx*4+yy],a[x*4+y]);
            H+=cntH(xx*4+yy);
        }
    }
    return false;
}
int main()
{
    for (int i=0;i<16;i++)
        scanf("%d",&a[i]);
    if (fail())
        puts("TOO LONG");
    else{
        int H=0;
        for (int i=0;i<16;i++)
            if (a[i])
                H+=cntH(i);
        for (limit=0;limit<=10;limit++)
            if (dfs(0,st/4,st%4,H)){
                printf("%d\n",limit);
                break;
            }
        if (limit==11)
            puts("TOO LONG");
    }
}
