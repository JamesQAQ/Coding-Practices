#include <cstdio>

int main()
{
    int a,b;
    for (int i=0;i<7;i++){
        scanf("%d %d",&a,&b);
        if (a+b>8){
            printf("%d\n",i+1);
            return 0;
        }
    }
    puts("0");
}
