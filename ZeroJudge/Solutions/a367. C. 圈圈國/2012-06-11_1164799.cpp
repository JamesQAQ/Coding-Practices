#include <cstdio>
#include <algorithm>

int main()
{
    int cases,a[10000],tmp,n;
    scanf("%d",&cases);
    while (cases--){
        scanf("%d",&n);
        scanf("%d",&a[0]);
        for (int i=1;i<n;i++)
            scanf("%d",&tmp),a[i]=a[i-1]+tmp;
        std::stable_sort(a,a+n);
        int f=a[0],k=1,ans=0;
        for (int i=1;i<n;i++){
            if (a[i]!=f)
                f=a[i],k=0;
            k++;
            if (k>ans)
                ans=k;
        }
        printf("%d\n",ans);
    }
}
