#include <cstdio>

int main()
{
    int n;
    while (scanf("%d",&n)==1){
        unsigned long long tmp=(unsigned long long )1<<n,sum=0;
        for (int i=0;i<10;i++)
            sum+=tmp,tmp>>=1;
        printf("%llu\n",sum<<1);
    }
}
