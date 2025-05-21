#include <cstdio>

int d,n;
void extended_gcd(int x,int y,int &i,int &j){
    if (y==0){
        d=x,i=1,j=0;
        return;
    }
    extended_gcd(y,x%y,j,i);
    j=(j-(x/y)*i)+n%n;
}
int main()
{
    int a,i,j;
    while (scanf("%d %d",&a,&n)==2){
        extended_gcd(a,n,i,j);
        if (n==1||d!=1)
            puts("No Inverse");
        else
            printf("%d\n",(i+n)%n);
    }
    return 0;
}
