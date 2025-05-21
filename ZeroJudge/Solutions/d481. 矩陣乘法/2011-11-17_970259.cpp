#include <cstdio>

int main()
{
    int N,M,n,m,A[100][100],a[100][100];
    long long ans[100][100];
    while (scanf("%d %d %d %d",&N,&M,&n,&m)==4){
        if (M!=n)
            puts("Error");
        else{
            for (int i=0;i<N;i++)
                for (int j=0;j<M;j++)
                    scanf("%d",&A[i][j]);
            for (int i=0;i<n;i++)
                for (int j=0;j<m;j++)
                    scanf("%d",&a[i][j]);
            for (int i=0;i<N;i++)
                for (int j=0;j<m;j++){
                    long long tmp=0;
                    for (int k=0;k<M;k++)
                        tmp+=(long long)A[i][k]*a[k][j];
                    ans[i][j]=tmp;
                }
            for (int i=0;i<N;i++){
                for (int j=0;j<m;j++)
                    printf((j)?" %lld":"%lld",ans[i][j]);
                puts("");
            }
        }
    }
    return 0;
}
