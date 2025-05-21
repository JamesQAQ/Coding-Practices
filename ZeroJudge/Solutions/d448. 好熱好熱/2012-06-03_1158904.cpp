#include <cstdio>

int main()
{
    double t1,t2,t3,x1,x2,x3;
    while (scanf("%lf %lf %lf %lf %lf",&t1,&t2,&t3,&x1,&x3)==5){
        double v=(x3-x1)/(t3-t1);
        printf("%.6lf\n",x1+(t2-t1)*v);
    }
}
