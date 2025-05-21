#include <cstdio>

int main()
{
    long long n,m,ans[3];
    int temp,t[3];
    while (scanf("%lld %lld",&n,&m)==2){
        ans[0]=ans[1]=1;
        t[0]=0,t[1]=1,t[2]=2;
        for (int i=2;i<n;i++){
            ans[t[2]]=(ans[t[1]]*i+ans[t[0]]*(i-1))%m;
            temp=t[2],t[2]=t[0],t[0]=t[1],t[1]=temp;
        }
        printf("%lld\n",ans[(n-1)%3]);
    }
    return 0;
}
