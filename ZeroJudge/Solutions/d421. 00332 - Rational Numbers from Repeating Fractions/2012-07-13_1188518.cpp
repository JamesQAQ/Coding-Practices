#include <cstdio>
#include <cstring>

char s[100];
int len,num;
long long gcd(long long a,long long b){
    while ((a%=b)&&(b%=a));
    return (a==0)?b:a;
}
long long pow[20]={1};
int main()
{
    int cases=0;
    for (int i=1;i<20;i++)
        pow[i]=pow[i-1]*10;
    long long a,b;
    int j;
    while (scanf("%d",&j),j>=0){
        cases++;
        scanf("%s",s);
        len=strlen(s);
        a=0;
        for (int i=2;i<len;i++)
            a=a*10+s[i]-48;
        if (j==0)
            b=pow[len-2];
        else{
            a-=a/pow[j];
            b=pow[len-2]-pow[len-2-j];
        }
        //printf("%lld\n",b);
        printf("Case %d: %lld/%lld\n",cases,a/gcd(a,b),b/gcd(a,b));
    }
}
