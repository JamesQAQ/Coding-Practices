#include <cstdio>

int main()
{
    long long n;
    while (scanf("%lld",&n)==1){
        bool Stan=true;
        int k=2;
        long long tmp=9;
        while (n>tmp){
            Stan=!Stan;
            tmp*=(long long)k;
            k=11-k;
        }
        puts((Stan)?"Stan wins.":"Ollie wins.");
    }
}
