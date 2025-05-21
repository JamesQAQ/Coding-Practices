#include <cstdio>

unsigned long long dp[101][64]={};
int search(int k,unsigned long long n){
    int l=1,r=63,mid;
    while (l<=r){
        mid=(l+r)/2;
        if (dp[k][mid]>=n)
            r=mid-1;
        else
            l=mid+1;
    }
    return l;
}
int main()
{
    for (int i=1;i<=100;i++){
        for (int j=1;j<=63;j++){
            dp[i][j]=dp[i-1][j-1]+dp[i][j-1]+1;
            //printf("%I64u ",dp[i][j]);
        }
        //puts("");
        //getchar();
    }
    int k;
    unsigned long long n;
    while (scanf("%d %llu",&k,&n)){
        if (k==0)
            break;
        if (dp[k][63]<n)
            puts("More than 63 trials needed.");
        else
            printf("%d\n",search(k,n));
    }
}
