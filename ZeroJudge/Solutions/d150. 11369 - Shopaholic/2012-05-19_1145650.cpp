#include <cstdio>
#include <algorithm>

bool cmp(int i,int j){
    return i>j;
}
int main()
{
    int cases,n,a[20000];
    scanf("%d",&cases);
    while (cases--){
        scanf("%d",&n);
        for (int i=0;i<n;i++)
            scanf("%d",&a[i]);
        std::stable_sort(a,a+n,cmp);
        int ans=0;
        for (int i=2;i<n;i+=3)
            ans+=a[i];
        printf("%d\n",ans);
    }
}
