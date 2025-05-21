#include <cstdio>

int main()
{
    int n;
    while (scanf("%d",&n)==1){
        long long all=(long long)(1+n)*((n-1)/2+1)/2;
        long long st=all*2-1;
        //printf("%lld %lld\n",all,st);
        printf("%lld\n",3*st-6);
    }
}
