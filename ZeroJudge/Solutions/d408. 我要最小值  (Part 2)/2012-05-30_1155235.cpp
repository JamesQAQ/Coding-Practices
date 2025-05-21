#include <cstdio>
#include <cmath>

double line(double a,double b,double c){
    double p=sqrt(2*(a*a+b*b)-c*c)/3;
    return p*p;
}
int main()
{
    int n,a,b,c;
    while (scanf("%d",&n),n)
        while (n--){
            scanf("%d %d %d",&a,&b,&c);
            printf ("%.1lf\n",line(a,b,c)+line(b,c,a)+line(c,a,b));
        }        
}
