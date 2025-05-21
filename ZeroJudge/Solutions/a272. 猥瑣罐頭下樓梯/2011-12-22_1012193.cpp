#include <cstdio>

int mod=10007;
struct Node{
    int a[2][2];
    void operator *=(Node b){
        Node tmp;
        for (int i=0;i<2;i++)
            for (int j=0;j<2;j++)
                tmp.a[i][j]=a[i][j];
        for (int i=0;i<2;i++)
            for (int j=0;j<2;j++){
                int x=0;
                for (int k=0;k<2;k++)
                    x+=tmp.a[i][k]*b.a[k][j];
                a[i][j]=x%mod;
            }
    }
} a[32],ans;
int main()
{
    int n;
    a[0].a[0][0]=0;
    a[0].a[0][1]=a[0].a[1][0]=a[0].a[1][1]=1;
    for (int i=1;i<32;i++){
        a[i]=a[i-1];
        a[i]*=a[i-1];
    }
    while (scanf("%d",&n)==1){
        int A=0,B=1;
        for (int i=30,j=1<<30;i>=0;i--,j>>=1)
            if (n&j){
                int tmpA=A,tmpB=B;
                A=(tmpA*a[i].a[0][0]+tmpB*a[i].a[0][1])%mod;
                B=(tmpA*a[i].a[1][0]+tmpB*a[i].a[1][1])%mod;
            }
        printf("%d\n",B);
    }
}
