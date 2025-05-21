#include <cstdio>
#include <iostream>

struct Node{
    int a[100000],num;
} ans[2],*pre,*now;
int main()
{
    int a,n,mod=10;
    while (scanf("%d %d",&a,&n)==2){
        pre=&ans[1];
        now=&ans[0];
        now->num=now->a[0]=1;
        for (int i=512;i>0;i>>=1){
            std::swap(pre,now);
            now->num=2*pre->num-1;
            for (int j=0;j<now->num;j++)
                now->a[j]=0;
            for (int j=0;j<pre->num;j++)
                for (int k=0;k<pre->num;k++)
                    now->a[j+k]+=pre->a[j]*pre->a[k];
            for (int j=0;j<now->num-1;j++)
                if (now->a[j]>=mod){
                    now->a[j+1]+=now->a[j]/mod;
                    now->a[j]%=mod;
                }
            while (now->a[now->num-1]>=mod){
                now->a[now->num]=now->a[now->num-1]/mod;
                now->a[now->num-1]%=mod;
                now->num++;
            }
            if (i&n){
                for (int j=0;j<now->num;j++)
                    now->a[j]*=a;
                for (int j=0;j<now->num-1;j++)
                    if (now->a[j]>=mod){
                        now->a[j+1]+=now->a[j]/mod;
                        now->a[j]%=mod;
                    }
                while (now->a[now->num-1]>=mod){
                    now->a[now->num]=now->a[now->num-1]/mod;
                    now->a[now->num-1]%=mod;
                    now->num++;
                }
            }
        }
        printf("%d",now->a[now->num-1]);
        for (int i=now->num-2;i>=0;i--)
            printf("%d",now->a[i]);
        puts("");
    }
    return 0;
}
