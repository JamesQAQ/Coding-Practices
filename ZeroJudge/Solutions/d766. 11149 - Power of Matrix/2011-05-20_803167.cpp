#include <cstdio>

int A[40][40],n;
void count(int k,int a[40][40]){
    int at=1<<30;
    while (at>0){
        if (at&k)
            break;
        at>>=1;
    }
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            a[i][j]=A[i][j];
    at>>=1;
    while (at>0){
        int t[40][40];
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                t[i][j]=a[i][j];
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++){
                int temp=0;
                for (int k=0;k<n;k++)
                    temp+=t[i][k]*t[k][j];
                a[i][j]=temp%10;
            }
        if (at&k){
            for (int i=0;i<n;i++)
                for (int j=0;j<n;j++)
                    t[i][j]=a[i][j];
            for (int i=0;i<n;i++)
                for (int j=0;j<n;j++){
                    int temp=0;
                    for (int k=0;k<n;k++)
                        temp+=t[i][k]*A[k][j];
                    a[i][j]=temp%10;
                }
        }
        at>>=1;
    }
}
void count_sum(int k,int a[40][40]){
    if (k==1){
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                a[i][j]=A[i][j];
        return;
    }
    int b[40][40],c[40][40];
    count_sum(k/2,b);
    count(k/2,c);
    for (int i=0;i<n;i++)
        c[i][i]++;
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++){
            int temp=0;
            for (int k=0;k<n;k++)
                temp+=b[i][k]*c[k][j];
            a[i][j]=temp%10;
        }
    if (k%2){
        int d[40][40];
        count(k,d);
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++){
                a[i][j]+=d[i][j];
                a[i][j]%=10;
            }
    }
}
int main()
{
    int k;
    while (scanf("%d %d",&n,&k)){
        if (n==0)
            break;
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                scanf("%d",&A[i][j]);
        int ans[40][40];
        count_sum(k,ans);
        for (int i=0;i<n;i++){
            printf("%d",ans[i][0]);
            for (int j=1;j<n;j++)
                printf(" %d",ans[i][j]);
            puts("");
        }
        puts("");
    }
    return 0;
}
