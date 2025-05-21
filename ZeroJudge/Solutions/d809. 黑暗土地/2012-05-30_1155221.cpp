#include <cstdio>

struct Node {double x,y;} node[200];
double fabs(double x){
    return (x<.0)?-x:x;
}
double cross(Node &o,Node &a,Node &b){
    double ax=a.x-o.x,ay=a.y-o.y,bx=b.x-o.x,by=b.y-o.y;
    return ax*by-ay*bx;
}
int main()
{
    int n;
    while (scanf("%d",&n)==1){
        for (int i=0;i<n;i++)
            scanf("%lf %lf",&node[i].x,&node[i].y);
        double ans=.0;
        for (int i=0;i<n;i++)
            for (int j=i+1;j<n;j++)
                for (int k=j+1;k<n;k++){
                    double v=fabs(cross(node[i],node[j],node[k]))/2;
                    if (v>ans)
                        ans=v;
                }
        printf("%.2lf\n",ans);
    }
}
