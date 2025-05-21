#include <cstdio>

int main()
{
    int cases;
    double a,b,c,d;
    scanf("%d",&cases);
    while (cases--){
        scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
        if (b!=0.0||d!=0.0)
            puts("No");
        else{
            if (a>c)
                puts(">");
            else if (a<c)
                puts("<");
            else
                puts("=");
        }
    }
}
