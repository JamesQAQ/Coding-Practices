#include <cstdio>

int bit(int n){
    int i=1<<30,sum=0;
    for (;i>0;i>>=1)
        if (i&n)
            break;
    for (;i>0;i>>=1){
        printf("%d",(i&n)?1:0);
        if (i&n)
            sum++;
    }
    return sum;
}
void work(int n){
    printf("The parity of ");
    int tmp=bit(n);
    printf(" is %d (mod 2).\n",tmp);
}
int main()
{
    int n;
    while (scanf("%d",&n),n)
        work(n);
}
