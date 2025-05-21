#include <cstdio>

int a,b,c;
bool dp[10001];
bool test(){
    for (int i=1;i<=10000;i++)
        dp[i]=false;
    dp[0]=true;
    for (int i=a;i<=10000;i++)
        dp[i]=(dp[i]||dp[i-a]);
    for (int i=b;i<=10000;i++)
        dp[i]=(dp[i]||dp[i-b]);
    for (int i=c;i<=10000;i++)
        if (!dp[i])
            return false;
    return true;
}
int main()
{
    while (scanf("%d %d %d",&a,&b,&c)==3)
        (test())?puts("Yes"):puts("No");
    return 0;
}
