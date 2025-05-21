#include <cstdio>

int mod,tmp[2][2];
struct Martix{
    int a[2][2];
    void operator *=(Martix b){
        for (int i=0;i<2;i++)
            for (int j=0;j<2;j++){
                long long t=0;
                for (int k=0;k<2;k++)
                    t+=(long long)a[i][k]*b.a[k][j];
                tmp[i][j]=t%mod;
            }
        for (int i=0;i<2;i++)
            for (int j=0;j<2;j++)
                a[i][j]=tmp[i][j];
    }
    void init(){
        a[0][0]=a[1][1]=1;
        a[0][1]=a[1][0]=0;
    }
} a,ans;
int main()
{
    a.a[0][0]=0;
    a.a[0][1]=a.a[1][0]=a.a[1][1]=1;
    int n,m;
    while (scanf("%d %d",&n,&m)==2){
        if (n==0){
            puts("0");
            continue;
        }
        mod=1<<m;
        ans.init();
        n--;
        for (int i=1<<30;i>0;i>>=1){
            ans*=ans;
            if (i&n)
                ans*=a;
        }
        printf("%d\n",(ans.a[0][0]+ans.a[0][1])%mod);
    }
}
