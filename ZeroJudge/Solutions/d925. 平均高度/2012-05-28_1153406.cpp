#include <cstdio>

inline bool in(int x,int y,int n,int m){
    return x>=1&&x<=n&&y>=1&&y<=m;
}
int move[8][2]={{0,1},{1,0},{0,-1},{-1,0},{1,1},{1,-1},{-1,-1},{-1,1}};
int main()
{
    int n,m,t,a,b,k;
    scanf("%d %d %d",&n,&m,&t);
    long long ans=0;
    for (int i=0;i<t;i++){
        scanf("%d %d %d",&a,&b,&k);
        int x=-1;
        for (int i=0;i<8;i++)
            if (in(a+move[i][0],b+move[i][1],n,m))
                x++;
        ans+=x*k;
    }
    printf("%.2lf\n",(double)ans/((long long)n*m));
}
