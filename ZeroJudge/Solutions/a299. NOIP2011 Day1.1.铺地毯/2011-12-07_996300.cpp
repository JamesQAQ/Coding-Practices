#include <cstdio>

struct Node {int x[2],y[2];} rec[10000];
int x,y,n;
void test(){
    for (int i=n-1;i>=0;i--)
        if (rec[i].x[0]<=x&&x<=rec[i].x[0]+rec[i].x[1]&&rec[i].y[0]<=y&&y<=rec[i].y[0]+rec[i].y[1]){
            printf("%d\n",i+1);
            return;
        }
    puts("-1");
}
int main()
{
    while (scanf("%d",&n)==1){
        for (int i=0;i<n;i++)
            scanf("%d %d %d %d",&rec[i].x[0],&rec[i].y[0],&rec[i].x[1],&rec[i].y[1]);
        scanf("%d %d",&x,&y);
        test();
    }
}
