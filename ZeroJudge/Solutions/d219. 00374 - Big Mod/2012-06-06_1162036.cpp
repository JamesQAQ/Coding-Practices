#include <cstdio>

int main()
{
    int b,p,m;
    while (scanf("%d %d %d",&b,&p,&m)==3){
        b%=m;
        int x=1;
        for (int i=(1<<30);i>0;i>>=1){
            x*=x;
            x%=m;
            if (i&p){
                x*=b;
                x%=m;
            }
        }
        printf("%d\n",x);
    }
}
