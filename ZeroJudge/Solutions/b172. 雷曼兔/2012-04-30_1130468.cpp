#include <cstdio>

int x[2501],y[2501],dp[2501]={},n;
int Abs(int x){
    return (x<0)?-x:x;
}
int main()
{
    int tmp;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++){
            scanf("%d",&tmp);
            x[tmp]=i,y[tmp]=j;
        }
    for (int i=n*n;i>=1;i--)
        for (int j=i-1;j>=1;j--){
            int p=Abs(x[i]-x[j])+Abs(y[i]-y[j]),value=dp[i]+p*p;
            if (value>dp[j])
                dp[j]=value;
        }
    printf("%d\n",dp[1]);
}
