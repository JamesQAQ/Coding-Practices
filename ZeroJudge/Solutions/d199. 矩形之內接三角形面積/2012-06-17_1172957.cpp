#include <cstdio>
#include <cmath>

int main()
{
    int a,b,c;
    while (scanf("%d %d %d",&a,&b,&c)==3){
        int sum=a+b+c;
        printf("%d\n",(int)sqrt((double)sum*sum-4.0*a*c));
    }
}
