#include <cstdio>

int input(){
    char c=getchar();
    while (c>'9'||c<'0') c=getchar();
    int x=c-48;c=getchar();
    while (c<='9'&&c>='0') x=x*10+c-48,c=getchar();
    return x;
}
int main()
{
    int dp[1001],cases,n,a[10]={1,5,10,50,100,500,1000,30,70,110};
    for (int i=1;i<=1000;i++)
        dp[i]=i;
    dp[0]=0;
    for (int j=0;j<10;j++)
        for (int i=a[j];i<=1000;i++)
            if (dp[i-a[j]]+1<dp[i])
                dp[i]=dp[i-a[j]]+1;
    cases=input();
    while (cases--){
        n=input();
        printf("%d\n",n/1000+dp[n%1000]);
    }
}
