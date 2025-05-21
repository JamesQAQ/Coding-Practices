#include <cstdio>

int main()
{
    int n,a,b;
    while (scanf("%d %d %d",&a,&b,&n)==3){
        printf("%d.",a/b);
        a%=b;
        for (int i=0;i<n;i++){
            a*=10;
            putchar(a/b+48);
            a%=b;
        }
        puts("");
    }
    return 0;
}
