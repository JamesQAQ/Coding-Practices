#include <cstdio>

int gcd(int m,int n){
    while ((m%=n)&&(n%=m));
    return (m==0)?n:m;
}
int d=10000;
struct Node{
    int a[10],num;
    void init(){
        num=1,a[0]=1;
    }
    void print(){
        printf("%d",a[num-1]);
        for (int i=num-2;i>=0;i--)
            printf("%04d",a[i]);
    }
    void operator *=(int x){
        for (int i=0;i<num;i++)
            a[i]*=x;
        for (int i=0;i<num-1;i++)
            if (a[i]>=d){
                a[i+1]+=a[i]/d;
                a[i]%=d;
            }
        while (a[num-1]>=d){
            a[num]=a[num-1]/d;
            a[num-1]%=d;
            num++;
        }
    }
} ans;
int main()
{
    int n,m,a[101],om;
    while (scanf("%d %d",&n,&m),n+m){
        om=m;
        if (n-m<m)
            m=n-m;
        for (int i=n-m+1;i<=n;i++)
            a[i]=i;
        for (int i=2;i<=m;i++){
            int tmp=i;
            for (int j=n-m+1;j<=n;j++){
                if (tmp==1)
                    break;
                int g=gcd(tmp,a[j]);
                a[j]/=g,tmp/=g;
            }
        }
        ans.init();
        for (int i=n-m+1;i<=n;i++)
            ans*=a[i];
        printf("%d things taken %d at a time is ",n,om);
        ans.print();
        puts(" exactly.");
    }
}
