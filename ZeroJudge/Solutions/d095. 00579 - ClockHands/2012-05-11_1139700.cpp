#include <cstdio>

double fabs(double x){
    return (x<0)?-x:x;
}
double min(double a,double b){
    return (a<b)?a:b;
}
int main()
{
    int h,m;
    while (scanf("%d:%d",&h,&m),h+m){
        double x=fabs(h*30.0+m*0.5-m*6.0);
        printf("%.3lf\n",min(x,360.0-x));
    }
}
