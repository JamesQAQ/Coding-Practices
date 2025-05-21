#include <cstdio>

int main()
{
    int cases,n;
    scanf("%d",&cases);
    while (cases--){
        int ans=0,tmp,sum=0;
        scanf("%d",&n);
        for (int i=0;i<n;i++){
            scanf("%d",&tmp);
            sum+=tmp;
            if (sum==0)
                ans++;
        }
        printf("%d\n",ans);
    }
}
