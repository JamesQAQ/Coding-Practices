#include <cstdio>
#include <algorithm>

inline int max(int a,int b){
    return (a>b)?a:b;
}
int a[1000000];
int main()
{
    int n,ans=0;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        scanf("%d",&a[i]);
    std::stable_sort(a,a+n);
    for (int i=0;i<n;i++)
        ans=max(ans,a[i]-ans);
    printf("%d\n",ans);
}
