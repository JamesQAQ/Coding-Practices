#include <cstdio>

int main()
{
    int t,a,b,c;
    scanf("%d",&t);
    while (t--){
        scanf("%d %d %d",&a,&b,&c);
        if (a==1)
            printf("%lld\n",(long long)b+c);
        else if (a==2)
            printf("%lld\n",(long long)b-c);
        else if (a==3)
            printf("%lld\n",(long long)b*c);
        else
            printf("%d\n",b/c);
    }
    return 0;
}
