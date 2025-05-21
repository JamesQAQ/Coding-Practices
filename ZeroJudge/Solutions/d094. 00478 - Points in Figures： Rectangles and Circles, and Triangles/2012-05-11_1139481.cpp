#include <cstdio>
#include <cmath>

double eps=1e-6;
double dis(double ax,double ay,double bx,double by){
    double x=ax-bx,y=ay-by;
    return sqrt(x*x+y*y);
}
double Area(double ox,double oy,double ax,double ay,double bx,double by){
    double Ax=ax-ox,Ay=ay-oy,Bx=bx-ox,By=by-oy;
    return fabs(Ax*By-Bx*Ay);
}
struct Node {
    char c;
    double x[3],y[3],r,area;
    bool get(){
        scanf(" %c",&c);
        if (c=='*')
            return false;
        if (c=='r')
            scanf("%lf %lf %lf %lf",&x[0],&y[1],&x[1],&y[0]);
        if (c=='c')
            scanf("%lf %lf %lf",&x[0],&y[0],&r);
        if (c=='t')
            scanf("%lf %lf %lf %lf %lf %lf",&x[0],&y[0],&x[1],&y[1],&x[2],&y[2]),area=Area(x[0],y[0],x[1],y[1],x[2],y[2]);
        return true;
    }
    bool in(double X,double Y){
        if (c=='r')
            return (x[0]<X&&X<x[1]&&y[0]<Y&&Y<y[1]);
        if (c=='c')
            return (dis(x[0],y[0],X,Y)<r);
        if (c=='t'){
            double sum=0.0,tmp;
            for (int i=0;i<3;i++){
                tmp=Area(X,Y,x[i],y[i],x[(i+1)%3],y[(i+1)%3]);
                if (tmp==0.0)
                    return false;
                sum+=tmp;
            }
            return fabs(sum-area)<eps;
        }
        return false;
    }
} graph[100];

int main()
{
    int n=1;
    while (graph[n].get())
        n++;
    double x,y;
    int cnt=0;
    while (scanf("%lf %lf",&x,&y)){
        //printf("%.2lf %.2lf %.2lf %.2lf\n",graph[5].x[1],graph[5].y[1],graph[5].x[2],graph[5].y[2]);
        if (x==9999.9&&y==9999.9)
            break;
        cnt++;
        bool found=false;
        for (int i=1;i<=n;i++)
            if (graph[i].in(x,y))
                printf("Point %d is contained in figure %d\n",cnt,i),found=true;
        if (!found)
            printf("Point %d is not contained in any figure\n",cnt);
    }
}
