#include <cstdio>

int map[201][201]={},n,m;
void Line(int a,int b,int &d){
    if (a==b)
        d=0;
    else if (a>b)
        d=-1;
    else
        d=1;
}
bool illegal(int ax,int ay,int bx,int by){
    if (ax>m||ax<0||bx>m||bx<0||ay>n||ay<0||by>n||by<0)
        return true;
    if (map[ax][ay]<1||map[bx][by]<1)
        return true;
    if ((map[ax][ay]>1&&map[bx][by]<=1)||(map[ax][ay]<=1&&map[bx][by]>1))
        return true;
    return false;
}
int tri_1(int x,int y,int d){
    int ax=x-1,ty=y+d,bx=x+1;
    while (1){
        if (illegal(ax,ty,bx,ty))
            return 0;
        if (map[ax][ty]>1&&map[bx][ty]>1)
            break;
        ax--,bx++,ty+=d;
    }
    for (int i=ax+1;i<bx;i++)
        if (map[i][ty]!=1)
            return 0;
    ty-=d,ax++,bx--;
    while (ty!=y){
        for (int i=ax+1;i<bx;i++)
            if (map[i][ty])
                return 0;
        ty-=d,ax++,bx--;
    }
    return 1;
}
int tri_2(int x,int y,int d){
    int ay=y-1,by=y+1,tx=x+d;
    while (1){
        if (illegal(tx,ay,tx,by))
            return 0;
        if (map[tx][ay]>1&&map[tx][by]>1)
            break;
        ay--,by++,tx+=d;
    }
    for (int i=ay+1;i<by;i++)
        if (map[tx][i]!=1)
            return 0;
    tx-=d,ay++,by--;
    while (tx!=x){
        for (int i=ay+1;i<by;i++)
            if (map[tx][i])
                return 0;
        tx-=d,ay++,by--;
    }
    return 1;
}
int tri_3(int x,int y,int d){
    int ax=x-1,by=y+d;
    while (1){
        if (illegal(ax,y,x,by))
            return 0;
        if (map[ax][y]>1&&map[x][by]>1)
            break;
        ax--,by+=d;
    }
    for (int i=1;ax+i<x;i++)
        if (map[ax+i][y+d*i]!=1)
            return 0;
    for (int i=1;ax+i<x;i++)
        for (int j=1;j<i;j++)
            if (map[ax+i][y+j*d])
                return 0;
    return 1;
}
int tri_4(int x,int y,int d){
    int ax=x+1,by=y+d;
    while (1){
        if (illegal(ax,y,x,by))
            return 0;
        if (map[ax][y]>1&&map[x][by]>1)
            break;
        ax++,by+=d;
    }
    for (int i=1;ax-i>x;i++)
        if (map[ax-i][y+d*i]!=1)
            return 0;
    for (int i=1;ax-i>x;i++){
        for (int j=1;j<i;j++)
            if (map[ax-i][y+j*d])
                return 0;
    }
    return 1;
}
int main()
{
    int k,ax,ay,bx,by;
    scanf("%d %d %d",&m,&n,&k);
    n<<=2,m<<=2;
    for (int i=0;i<=n;i++)
        map[0][i]++,map[m][i]++;
    for (int i=0;i<=m;i++)
        map[i][0]++,map[i][n]++;
    for (int i=0;i<k;i++){
        scanf("%d %d %d %d",&ax,&ay,&bx,&by);
        int dx,dy;
        Line(ax,bx,dx),Line(ay,by,dy);
        ax<<=2,bx<<=2,ay<<=2,by<<=2;
        while (ax!=bx||ay!=by){
            map[ax][ay]++;
            ax+=dx,ay+=dy;
        }
        map[bx][by]++;
    }
    int ans=0;
    for (int i=0;i<=m;i++)
        for (int j=n;j>=0;j--)
            if (map[i][j]>1)
                ans+=tri_1(i,j,1)+tri_1(i,j,-1)+tri_2(i,j,1)+tri_2(i,j,-1)+tri_3(i,j,1)+tri_3(i,j,-1)+tri_4(i,j,1)+tri_4(i,j,-1);
    printf("%d\n",ans);
    return 0;
}
