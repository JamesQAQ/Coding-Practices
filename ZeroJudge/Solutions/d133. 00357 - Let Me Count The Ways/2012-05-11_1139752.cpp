#include <cstdio>

int main()
{
    long long dp[30001]={};
    int money[5]={1,5,10,25,50};
    dp[0]=1;
    for (int i=0;i<5;i++)
        for (int j=money[i];j<=30000;j++)
            dp[j]+=dp[j-money[i]];
    int n;
    while (scanf("%d",&n)==1){
        if (dp[n]==1)
            printf("There is only 1 way to produce %d cents change.\n",n);
        else
            printf("There are %lld ways to produce %d cents change.\n",dp[n],n);
    }
}
