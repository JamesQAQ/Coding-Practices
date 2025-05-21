#include <cstdio>

int main()
{
    int cases;
    double a,b;
    scanf("%d",&cases);
    while (cases--){
        scanf("%lf %lf",&a,&b);
        printf("%.3lf\n",(b-a*a/b)/b);
    }
}
