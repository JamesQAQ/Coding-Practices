#include <cstdio>

int n;
long long a[10][10],b[10][11],*p[10],*tmp;
long long Abs(long long x){
    return (x<0)?-x:x;
}
void row_gcd(long long *A,long long *B,int x){
    if (Abs(A[x])<Abs(B[x]))
        tmp=A,A=B,B=tmp;
    while (B[x]!=0){
        long long t=A[x]/B[x];
        for (int k=x;k<n;k++)
            A[k]-=t*B[k];
        tmp=A,A=B,B=tmp;
    }
}
long long det(){
    long long ans=-1;
    for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
            row_gcd(p[i],p[j],i);
            if (p[i][i]==0&&p[j][i]!=0){
                tmp=p[i],p[i]=p[j],p[j]=tmp;
                ans*=-1;
            }
        }
        ans*=p[i][i];
    }
    return ans;
}
long long gcd(long long a,long long b){
    while ((a%=b)&&(b%=a));
    return (a==0)?b:a;
}
void work(){
    long long Det,detd[10];
    for (int i=0;i<n;i++){
        p[i]=a[i];
        for (int j=0;j<n;j++)
            a[i][j]=b[i][j];
    }
    Det=det();
    for (int k=0;k<n;k++){
        for (int i=0;i<n;i++){
            p[i]=a[i];
            for (int j=0;j<n;j++)
                a[i][j]=b[i][j];
        }
        for (int i=0;i<n;i++)
            a[i][k]=b[i][n];
        detd[k]=det();
        if (Det<0)
            detd[k]=-detd[k];
        if (detd[k]&&!Det){
            puts("0");
            return;
        }
    }
    if (!Det){
        puts("N");
        return;
    }
    if (Det<0)
        Det=-Det;
    puts("1");
    for (int i=0;i<n;i++){
        long long g=gcd(Det,Abs(detd[i]));
        printf("x%d = %d",i+1,detd[i]/g);
        if (Det/g>1)
            printf("/%d",Det/g);
        puts("");
    }
}
int main()
{
    scanf("%d",&n);
        for (int i=0;i<n;i++)
            for (int j=0;j<n+1;j++)
                scanf("%lld",&b[i][j]);
        work();
}
