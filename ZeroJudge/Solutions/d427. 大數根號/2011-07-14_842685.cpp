#include <cstdio>

int d[120]={},num,ans[60];
void print(){
    for (int i=num-1;i>=0;i--)
        printf("%d",d[i]);
    puts("");
}
void init(int n){
    for (int i=0;i<100;i++)
        d[i]=0;
    num=100;
    while (n!=0){
        d[num++]=n%10;
        n/=10;
    }
    if (num%2)
        d[num++]=0;
}
bool ok(int at,int x){
    int a[120],n=num/2-at/2;
    a[0]=x*x;
    for (int i=at/2+1;i<num/2;i++)
        a[i-at/2]=ans[i]*2*x;
    for (int i=0;i<n-1;i++)
        if (a[i]>=10){
            a[i+1]+=a[i]/10;
            a[i]%=10;
        }
    while (a[n-1]>=10){
        a[n]=a[n-1]/10;
        a[n-1]%=10;
        n++;
    }
    a[n]=0;
    for (int i=n;i>=0;i--){
        if (a[i]>d[at+i])
            return true;
        if (a[i]<d[at+i])
            return false;
    }
    return false;
}
void cut(int at,int x){
    int a[120],n=num/2-at/2;
    a[0]=x*x;
    for (int i=at/2+1;i<num/2;i++)
        a[i-at/2]=ans[i]*2*x;
    for (int i=0;i<n-1;i++)
        if (a[i]>=10){
            a[i+1]+=a[i]/10;
            a[i]%=10;
        }
    while (a[n-1]>=10){
        a[n]=a[n-1]/10;
        a[n-1]%=10;
        n++;
    }
    for (int i=0;i<n;i++)
        d[i+at]-=a[i];
    for (int i=at;i<num;i++)
        if (d[i]<0){
            d[i+1]--;
            d[i]+=10;
        }
}
int main()
{
    int n;
    while (scanf("%d",&n)==1){
        init(n);
        int start=d[num-1]*10+d[num-2],f=0;
        for (int i=1;i<10;i++){
            if (i*i>start)
                break;
            f=i;
        }
        ans[num/2-1]=f;
        d[num-2]-=f*f;
        while (d[num-2]<0){
            d[num-1]--;
            d[num-2]+=10;
        }
        for (int i=num-4;i>=0;i-=2){
            f=0;
            for (int j=1;j<10;j++){
                if (ok(i,j))
                    break;
                f=j;
            }
            cut(i,f);
            ans[i/2]=f;
        }
        for (int i=num/2-1;i>=50;i--)
            printf("%d",ans[i]);
        printf(".");
        for (int i=49;i>=0;i--)
            printf("%d",ans[i]);
        puts("");
    }
    return 0;
}
