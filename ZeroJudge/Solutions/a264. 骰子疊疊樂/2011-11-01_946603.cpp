#include <cstdio>

int judge(int n){
    for (int i=40;i>=30;i--)
        if (n>=i&&(n-i)%14==0)
            return (n-i)/14+2;
    return -1; 
}
int main()
{
    int n;
    while (scanf("%d",&n)==1){
        if (n<21||(n>21&&n<30))
            puts("-1");
        else if (n==21)
            puts("1");
        else
            printf("%d\n",judge(n));
    }
    return 0;
}
