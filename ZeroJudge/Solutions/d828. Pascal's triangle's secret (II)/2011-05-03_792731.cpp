#include <cstdio>
using namespace std;

int main()
{
    int n,f[32][2][2]={{{0,1},{1,1}}},ans[2][2],temp[2][2];
    for (int i=1;i<32;i++)
        for (int j=0;j<2;j++)
            for (int k=0;k<2;k++){
                int sum=0;
                for (int l=0;l<2;l++)
                    sum+=f[i-1][j][l]*f[i-1][l][k];
                f[i][j][k]=sum%10000;
            }
    while (scanf("%d",&n)==1){
        if (n==0){
            puts("1");
            continue;
        }
        int at=1,d=0;
        for (;d<32;d++){
            if (at&n){
                for (int i=0;i<2;i++)
                    for (int j=0;j<2;j++)
                        ans[i][j]=f[d][i][j];
                break;
            }
            at<<=1;
        }
        d++;
        at<<=1;
        for (;d<32;d++){
            if (at&n){
                for (int i=0;i<2;i++)
                    for (int j=0;j<2;j++)
                        temp[i][j]=ans[i][j];
                for (int i=0;i<2;i++)
                    for (int j=0;j<2;j++){
                        int sum=0;
                        for (int k=0;k<2;k++)
                            sum+=temp[i][k]*f[d][k][j];
                        ans[i][j]=sum%10000;
                    }
            }
            at<<=1;
        }
        printf("%d\n",(ans[0][0]+ans[0][1])%10000);
    }
    return 0;
}
