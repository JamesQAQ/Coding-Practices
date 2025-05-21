#include <cstdio>
#include <cmath>

int main()
{
    double pi=2*acos(.0),r,m;
    while (scanf("%lf %lf",&r,&m)==2){
        double ans=(1+m)*r*pi*2/m-2*r*pi/m;
        printf("%.5lf\n",ans);
    }
}
