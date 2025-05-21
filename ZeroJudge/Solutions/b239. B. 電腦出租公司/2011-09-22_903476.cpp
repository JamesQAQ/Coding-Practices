#include <cstdio>

int n,a[1000000];
long long m;
int input(){
    char c=getchar();
    while (c==' '||c=='\n')
        c=getchar();
    int x=c-48;
    c=getchar();
    while (c!=' '&&c!='\n'){
        x=x*10+c-48;
        c=getchar();
    }
    return x;
}
long long test(long long v){
    long long sum=0,cnt=0;
    int at=0;
    for (int i=0;i<n;i++){
        sum+=(long long)a[i];
        while (sum>=v&&at<=i)
            sum-=(long long)a[at++];
        cnt+=(long long)i-at+1;
    }
    return cnt;
}
int main()
{
    int t;
    scanf("%d",&t);
    while (t--){
        scanf("%d %lld",&n,&m);
        long long sum=0,mini=10001;
        for (int i=0;i<n;i++){
            a[i]=input();
            sum+=(long long)a[i];
            if (a[i]<mini)
                mini=a[i];
        }
        long long l=mini,r=sum,mid;
        while (l<=r){
            mid=(l+r)/2;
            long long c=test(mid);
            if (c>m-1)
                r=mid-1;
            else
                l=mid+1;
        }
        printf("%lld\n",(l-1)%(long long)1000000007);
    }
    return 0;
}
