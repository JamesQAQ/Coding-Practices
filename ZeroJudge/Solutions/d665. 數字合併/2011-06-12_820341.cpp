#include <cstdio>

int input(){
    char c=getchar();
    while (c==' '||c=='\n')
        c=getchar();
    int x=c-48;
    c=getchar();
    while (c!=' '&&c!='\n'){
        x=x*10+c-48;
        c=getchar();
    }
    return x;
}
int main()
{
    int a,b,n;
    long long ans=0;
    n=input();
    a=input();
    for (int i=1;i<n;i++){
        b=input();
        ans+=(a>b)?(long long)a:(long long)b;
        a=b;
    }
    printf("%lld\n",ans);
    return 0;
}
