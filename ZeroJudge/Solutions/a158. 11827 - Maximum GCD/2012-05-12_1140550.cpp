#include <cstdio>

long long gcd(long long m,long long n){
    while ((m%=n)&&(n%=m));
    return (m==0)?n:m;
}
int main()
{
    int cases,n;
    long long a[200];
    char s[100001];
    scanf("%d",&cases);
    gets(s);
    while (cases--){
        n=0;
        gets(s);
        long long ans=0,x=0;
        for (int i=0;s[i];i++){
            if (s[i]==' '&&x!=0){
                a[n++]=x;
                x=0;
            }
            else if (s[i]<='9'&&s[i]>='0')
                x=x*10+s[i]-48;
        }
        if (x!=0)
            a[n++]=x;
        for (int i=0;i<n;i++)
            for (int j=i+1;j<n;j++){
                long long g=gcd(a[i],a[j]);
                if (g>ans)
                    ans=g;
            }
        printf("%lld\n",ans);
    }
}
