#include <cstdio>
#include <cmath>

bool one;
int n;
void work(int a,int b){
    if ((a+b-1)%2!=0)
        return;
    if ((b-a+1)%2!=0)
        return;
    int r=(a+b-1)/2,l=(b-a+1)/2;
    if (0<l&&l<r&&r<n)
        printf("%d-%d\n",l,r),one=true;
}
int main()
{
    while (scanf("%d",&n)==1){
        n<<=1;
        one=false;
        for (int i=sqrt(n);i>=1;i--)
            if (n%i==0){
                work(i,n/i);
                work(n/i,i);
            }
        if (!one)
            puts("No Solution...");
    }
}
