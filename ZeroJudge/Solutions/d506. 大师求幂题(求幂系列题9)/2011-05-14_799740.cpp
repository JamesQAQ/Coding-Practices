#include <cstdio>

unsigned long long a[17][40000]={},ans[2][40000],ansnum[2],num[17],d=100000000,n=86495,sum=0;
int main()
{
    a[0][0]=7;
    num[0]=1;
    for (int i=1;i<17;i++){
        num[i]=2*num[i-1]-1;
        for (int j=0;j<num[i-1];j++)
            for (int k=0;k<num[i-1];k++)
                a[i][j+k]+=a[i-1][j]*a[i-1][k];
        for (int j=0;j<num[i]-1;j++)
            if (a[i][j]>=d){
                a[i][j+1]+=a[i][j]/d;
                a[i][j]%=d;
            }
        while (a[i][num[i]-1]>=d){
            a[i][num[i]]=a[i][num[i]-1]/d;
            a[i][num[i]-1]%=d;
            num[i]++;
        }
    }
    ans[0][0]=ansnum[0]=1;
    int at=1;
    for (int i=0;i<17;i++){
        if (n&at){
            sum++;
            int x=sum%2,f=(sum-1)%2;
            ansnum[x]=ansnum[f]+num[i]-1;
            for (int j=0;j<ansnum[x];j++)
                ans[x][j]=0;
            for (int j=0;j<ansnum[f];j++)
                for (int k=0;k<num[i];k++)
                    ans[x][j+k]+=ans[f][j]*a[i][k];
            for (int j=0;j<ansnum[x]-1;j++)
                if (ans[x][j]>=d){
                    ans[x][j+1]+=ans[x][j]/d;
                    ans[x][j]%=d;
                }
            while (ans[x][ansnum[x]-1]>=d){
                ans[x][ansnum[x]]=ans[x][ansnum[x]-1]/d;
                ans[x][ansnum[x]-1]%=d;
                ansnum[x]++;
            }
        }
        at<<=1;
    }
    int x=sum%2;
    printf("%lld",ans[x][ansnum[x]-1]);
    for (int i=ansnum[x]-2;i>=0;i--)
        printf("%08lld",ans[x][i]);
    puts("");
    return 0;
}
