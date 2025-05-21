#include <cstdio>
#include <cmath>

inline int CS(int x){
    return ((long long)(x+1)*x)>>1;
}
int a[100000];
int main()
{
    int n;
    while (scanf("%d",&n)==1){
        int p=(int)sqrt(n-1)+1;
        long long all=(long long)p*p;
        for (int i=1;i<=p;i++)
            a[i]=i;
        long long need=all-n,sum=0;
        int cut=0;
        for (cut=1;cut<=p;cut++){
            if (sum+cut*(p-cut+1)>need)
                break;
            sum+=cut*(p-cut+1);
        }
        cut--;
        need-=sum;
        for (int i=1;i<=p;i++){
            if (cut>=a[i])
                a[i]=0;
            else{
                a[i]-=cut;
                if (p-i+1<=need)
                    a[i]--;
            }
        }
        bool first=true;
        for (int i=1;i<=p;i++)
            if (a[i]){
                if (first)
                    first=false;
                else
                    putchar(' ');
                printf("%d",a[i]);
            }
        for (int i=p-1;i>0;i--)
            printf(" %d",i);
        puts("");
    }
}
