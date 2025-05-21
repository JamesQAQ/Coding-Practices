#include <cstdio>

int main()
{
    int n,at[8],sum[5][5];
    for (int i=0;i<=4;i++)
        sum[i][i]=0;
    while (scanf("%d",&n)==1){
        for (int i=0;i<4;i++)
            scanf("%d",&sum[i][i+1]);
        for (int i=2;i<=4;i++)
            for (int j=0;j+i<5;j++)
                sum[j][i+j]=sum[j][i+j-1]+sum[i+j-1][i+j];
        for (int i=0;i<8;i++)
            scanf("%d",&at[i]);
        bool ok=true;
        for (int i=1;i<8;i++){
            int a=at[i-1]-1,b=at[i]-1;
            if (a>b)
                a^=b^=a^=b;
            if (sum[a][b]>n){
                ok=false;
                break;
            }
        }
        puts((ok)?"yes":"no");
    }
    return 0;
}
