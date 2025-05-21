#include <cstdio>

struct Node {long long int a,b,c,d;} dp[25];
int main()
{
    int cases;
    long long t,m;
    scanf("%d",&cases);
    while (cases--){
        scanf("%lld %lld %lld %lld %lld %lld",&dp[0].a,&dp[0].b,&dp[0].c,&dp[0].d,&t,&m);
        for (int i=1;i<25;i++){
            dp[i].a=((dp[i-1].a*dp[i-1].a)%m+(dp[i-1].b*dp[i-1].c)%m)%m;
            dp[i].a=(dp[i].a+m)%m;
            dp[i].b=((dp[i-1].a*dp[i-1].b)%m+(dp[i-1].b*dp[i-1].d)%m)%m;
            dp[i].b=(dp[i].b+m)%m;
            dp[i].c=((dp[i-1].c*dp[i-1].a)%m+(dp[i-1].d*dp[i-1].c)%m)%m;
            dp[i].c=(dp[i].c+m)%m;
            dp[i].d=((dp[i-1].c*dp[i-1].b)%m+(dp[i-1].d*dp[i-1].d)%m)%m;
            dp[i].d=(dp[i].d+m)%m;
        }
        int at=1,T=1,H=1,tempT,tempH;
        for (int i=0;i<25;i++){
            if (at&t){
                tempT=T,tempH=H;
                T=((dp[i].a*tempT)%m+(dp[i].b*tempH)%m)%m;
                H=((dp[i].c*tempT)%m+(dp[i].d*tempH)%m)%m;
                T=(T+m)%m;
                H=(H+m)%m;
            }
            at<<=1;
        }
        if (T==H)
            puts("Normal");
        else
            (T>H)?puts("Tsundere"):puts("Haraguroi");
    }
    return 0;
}
