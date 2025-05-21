#include <cstdio>

int main()
{
    double a,b;
    char s[1000],c;
    int oo=2147483647;
    while (gets(s)!=NULL){
        puts(s);
        sscanf(s,"%lf %c %lf",&a,&c,&b);
        if (a>oo)
            puts("first number too big");
        if (b>oo)
            puts("second number too big");
        if (c=='+')
            a+=b;
        if (c=='*')
            a*=b;
        if (a>oo)
            puts("result too big");
    }
}
