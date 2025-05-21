#include <cstdio>
#include <algorithm>

int a[10000];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        scanf("%d",&a[i]);
    std::stable_sort(a,a+n);
    long long ans=0,lsum=0,rsum=0;
    int lnum=0,rnum=n-1;
    for (int i=1;i<n;i++)
        rsum+=(long long)a[i]-a[0];
    ans+=rsum;
    for (int i=1;i<n;i++){
        int d=a[i]-a[i-1];
        lnum++;
        lsum+=(long long)d*lnum;
        rsum-=(long long)d*rnum;
        rnum--;
        ans+=lsum+rsum;
    }
    printf("%lld\n",ans);
    //while (1);
}
