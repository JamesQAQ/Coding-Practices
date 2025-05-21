#include <stdio.h>
#include <algorithm>

int abs(int x){
    return (x<0)?-x:x;
}
int main()
{
    int cases,a[500];
    scanf("%d",&cases);
    while (cases--){
        int r;
        scanf("%d",&r);
        for (int i=0;i<r;i++)
            scanf("%d",&a[i]);
        std::stable_sort(a,a+r);
        int mid=r/2;
        long long ans=0;
        for (int i=0;i<r;i++)
            ans+=(long long)abs(a[i]-a[mid]);
        printf("%lld\n",ans);
    }
}
