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
    bool p[7001]={};
    p[2]=true;
    int cases,a,b,dp[7001];
    for (int i=3;i<7000;i+=2)
        p[i]=true;
    for (int i=3;i<=83;i+=2)
        if (p[i])
            for (int j=i*i;j<7000;j+=2*i)
                p[j]=false;
    dp[0]=0;
    for (int i=1;i<=7000;i++)
        dp[i]=dp[i-1]+((p[i])?0:i);
    cases=input();
    while (cases--){
        a=input();
        b=input();
        printf("%d\n",dp[b]-dp[a-1]);
    }
    return 0;
}
