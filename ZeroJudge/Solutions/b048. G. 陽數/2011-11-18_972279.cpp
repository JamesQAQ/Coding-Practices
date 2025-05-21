#include <cstdio>

long long C[55][55]={},A[55],pow2[55];
long long cnt(long long x){
    int num;
    for (int i=54;i>=0;i--){
        if (pow2[i]&x){
            num=i+1;
            break;
        }
    }
    long long ans=A[num];
    int d=num/2+1,sum=1;
    for (int i=num-2;i>=0;i--)
        if (pow2[i]&x){
            ans+=C[i][(d-sum<0)?0:d-sum];
            sum++;
        }
    if (sum>=d)
        ans++;
    return ans;
}
int main()
{
    pow2[0]=1;
    for (int i=1;i<=54;i++)
        pow2[i]=pow2[i-1]<<1;
    C[0][0]=1;
    for (int i=1;i<=54;i++){
        C[i][0]=1;
        for (int j=1;j<=i;j++)
            C[i][j]=C[i][j-1]*(i-j+1)/j;
        for (int j=i-1;j>=0;j--)
            C[i][j]+=C[i][j+1];
    }
    A[1]=0;
    for (int i=2;i<=55;i++)
        A[i]=A[i-1]+C[i-2][(i-1)/2];
    A[1]=0;
    int t;
    long long m;
    scanf("%d",&t);
    while (t--){
        scanf("%lld",&m);
        printf("%lld\n",cnt(m));
    }
    return 0;
}
