#include <cstdio>

int main()
{
    int a,b,c,d;
    while (scanf("%d %d %d %d",&a,&b,&c,&d)==4){
        if (a==0&&b==0&&c==0&&d==0)
            break;
        int delta=a*d-b*c;
        if (delta==0)
            puts("cheat!");
        else{
            a^=d^=a^=d;
            b=-b,c=-c;
            printf("%.5lf %.5lf\n%.5lf %.5lf\n",(double)a/delta,(double)b/delta,(double)c/delta,(double)d/delta);
        }
    }
    return 0;
}
