#include <cstdio>

int mod=1234567,dp[100001]={};
int input(){
    char c=getchar();
    while (c>'9'||c<'0') c=getchar();
    int x=c-48;c=getchar();
    while (c<='9'&&c>='0') x=x*10+c-48,c=getchar();
    return x;
}
int main()
{
    int n,m,to;
    n=input();
    dp[1]=1;
    for (int i=1;i<=n;i++){
        m=input();
        for (int j=0;j<m;j++){
            to=input();
            dp[to]+=dp[i];
            if (dp[to]>=mod)
                dp[to]-=mod;
        }
    }
    printf("%d\n",dp[n]);
}
