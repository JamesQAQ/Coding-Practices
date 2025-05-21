#include <cstdio>

int main()
{
    int a,b,c,d,e,f;
    while (scanf("%d %d %d %d %d %d",&a,&b,&c,&d,&e,&f)==6){
        long long delta=(long long)a*e-b*d,delta_y=(long long)a*f-d*c,delta_x=(long long)c*e-b*f;
        if (delta==0)
            puts((delta_x==0&&delta_y==0)?"Too many":"No answer");
        else
            printf("x=%.2lf\ny=%.2lf\n",(double)delta_x/delta,(double)delta_y/delta);
    }
}
