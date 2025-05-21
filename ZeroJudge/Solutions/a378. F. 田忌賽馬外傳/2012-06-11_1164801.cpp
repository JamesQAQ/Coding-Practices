#include <cstdio>
#include <algorithm>

int a[100000],b[100000];
int main()
{
    int n,k,cases;
    scanf("%d",&cases);
    while (cases--){
        scanf("%d %d",&n,&k);
        for (int i=0;i<n;i++)
            scanf("%d",&a[i]);
        for (int i=0;i<n;i++)
            scanf("%d",&b[i]); 
        std::stable_sort(a,a+n);
        std::stable_sort(b,b+n);
        int ans=0;
        for (int i=0;i<k;i++){
            int v=b[i]-a[n-k+i]+1;
            if (v>ans)
                ans=v;
        }
        printf("%d\n",ans);
    }    
}
