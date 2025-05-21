#include <stdio.h>

void shift(int a[],int num){
    int tmp=a[0];
    for (int i=0;i<num-1;i++)
        a[i]=a[i+1];
    a[num-1]=tmp;
}

void f(int a[],int n,int k){
    int b[k],num;
    for (int i=0;i<n;i+=k){
        num=0;
        for (int j=0;j<k&&i+j<n;j++)
            b[num++]=a[i+j];
        shift(b,num);
        for (int j=0;j<k&&i+j<n;j++)
            a[i+j]=b[j];
    }
}

int main()
{
    int n,a[1000];
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        a[i]=i+1;
    for (int i=1;i<=n;i++)
        f(a,n,i);
    for (int i=0;i<n;i++)
        printf((i)?" %d":"%d",a[i]);
}
