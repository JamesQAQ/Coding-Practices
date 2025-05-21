#include <cstdio>

int main()
{
    int cases;
    long long dp[31][4],n,m,d,t;
    dp[0][0]=0;
    dp[0][1]=1;
    dp[0][2]=dp[0][3]=2;
    scanf("%d",&cases);
    while (cases--){
        scanf("%lld %lld %lld %lld",&n,&m,&d,&t);
        for (int i=1;i<31;i++){
            dp[i][0]=((dp[i-1][0]*dp[i-1][0])%n+(dp[i-1][1]*dp[i-1][2])%n)%n;
            dp[i][1]=((dp[i-1][1]*dp[i-1][0])%n+(dp[i-1][1]*dp[i-1][3])%n)%n;
            dp[i][2]=((dp[i-1][2]*dp[i-1][0])%n+(dp[i-1][2]*dp[i-1][3])%n)%n;
            dp[i][3]=((dp[i-1][1]*dp[i-1][2])%n+(dp[i-1][3]*dp[i-1][3])%n)%n;
        }
        d%=n;
        long long tempm,tempd;
        for (int i=0,j=1;i<31;i++,j<<=1)
            if (t&j){
                tempm=m;
                tempd=d;
                m=((dp[i][0]*tempm)%n+(dp[i][1]*tempd)%n)%n;
                d=((dp[i][2]*tempm)%n+(dp[i][3]*tempd)%n)%n;
            }
        printf("%lld %lld\n",m,d);
    }
    return 0;
}
