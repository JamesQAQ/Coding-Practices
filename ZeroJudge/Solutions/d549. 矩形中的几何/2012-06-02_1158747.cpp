#include <cstdio>
#include <cmath>

int main()
{
    double a,b,c;
    while (scanf("%lf %lf %lf",&a,&b,&c)==3)
        printf("%.2lf\n",sqrt(a*a+c*c-b*b));
}
