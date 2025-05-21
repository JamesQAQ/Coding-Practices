#include <cstdio>

int ans[100][100];
void work1(int n){
    int l=0,r=n-1,u=0,d=n-1,cnt=1,Max=n*n;
    while (cnt<=Max){
        for (int i=l;i<=r;i++)
            ans[u][i]=cnt++;
        u++;
        for (int i=u;i<=d;i++)
            ans[i][r]=cnt++;
        r--;
        for (int i=r;i>=l;i--)
            ans[d][i]=cnt++;
        d--;
        for (int i=d;i>=u;i--)
            ans[i][l]=cnt++;
        l++;
    }
}
void work2(int n){
    int l=0,r=n-1,u=0,d=n-1,cnt=1,Max=n*n;
    while (cnt<=Max){
        for (int i=u;i<=d;i++)
            ans[i][l]=cnt++;
        l++;
        for (int i=l;i<=r;i++)
            ans[d][i]=cnt++;
        d--;
        for (int i=d;i>=u;i--)
            ans[i][r]=cnt++;
        r--;
        for (int i=r;i>=l;i--)
            ans[u][i]=cnt++;
        u++;
    }
}
int main()
{
    int cases,n,m;
    scanf("%d",&cases);
    while (cases--){
        scanf("%d %d",&n,&m);
        (m==1)?work1(n):work2(n);
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++)
                printf("%5d",ans[i][j]);
            puts("");
        }
        puts("");
    }
}
