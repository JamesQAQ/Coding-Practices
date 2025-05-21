#include <cstdio>

int mod=100019,d[31][2][2];
int main()
{
    d[0][0][0]=0;
    d[0][0][1]=d[0][1][0]=d[0][1][1]=1;
    int n;
    scanf("%d",&n);
    for (int i=1,j=2;i<31&&j<n;i++,j<<=1){
        for (int j=0;j<2;j++)
            for (int k=0;k<2;k++){
                long long temp=0;
                for (int l=0;l<2;l++)
                    temp+=(long long)d[i-1][j][l]*d[i-1][l][k];
                d[i][j][k]=temp%mod;
            }
    }
    n-=2;
    int a=1,b=1,ta,tb;
    for (int i=0,j=1;i<31&&n&&j<=n;i++,j<<=1)
        if (j&n){
            ta=a,tb=b;
            a=((long long)d[i][0][0]*ta+(long long)d[i][0][1]*tb)%mod;
            b=((long long)d[i][1][0]*ta+(long long)d[i][1][1]*tb)%mod;
        }
    printf("%d\n",(b-a/2+mod)%mod);
    return 0;
}
