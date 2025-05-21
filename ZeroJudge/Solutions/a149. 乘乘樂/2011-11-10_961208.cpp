#include <cstdio>

long long cnt(int x){
    if (x==0)
        return 0;
    long long ans=1;
    while (x!=0&&ans!=0)
        ans*=x%10,x/=10;
    return ans;
}
int main()
{
    int n,t;
    scanf("%d",&t);
    while (t--){
        scanf("%d",&n);
        printf("%lld\n",cnt(n));
    }
    return 0;
}
