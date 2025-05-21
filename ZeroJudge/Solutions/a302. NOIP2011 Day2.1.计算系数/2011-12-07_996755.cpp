#include <cstdio>

int mod=10007;
void extended_gcd(int a,int b,int &i,int &j){
    if (b==0){
        i=1,j=0;
        return;
    }
    extended_gcd(b,a%b,j,i);
    j=(j-(a/b)*i)%mod;
    if (j<0)
        j+=mod;
}
int C(int n,int m){
    if (n-m<m)
        m=n-m;
    int a=1,b=1,i,j;
    for (int i=1;i<=m;i++){
        a=(a*(n-i+1))%mod;
        b=(b*i)%mod;
    }
    extended_gcd(b,mod,i,j);
    return (a*i)%mod;
}
int main()
{
    int a,b,k,n,m,ans=1;
    scanf("%d %d %d %d %d",&a,&b,&k,&n,&m);
    a%=mod,b%=mod;
    for (int i=0;i<n;i++)
        ans=(ans*a)%mod;
    for (int i=0;i<m;i++)
        ans=(ans*b)%mod;
    printf("%d\n",(ans*C(k,n))%mod);
    return 0;
}
