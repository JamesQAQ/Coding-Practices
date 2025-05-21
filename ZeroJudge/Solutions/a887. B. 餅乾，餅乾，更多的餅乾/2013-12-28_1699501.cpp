#include <stdio.h>

int max(int a,int b){
    return (a>b)?a:b;
}

int main()
{
    int cases,n;
    scanf("%d",&cases);
    while (cases--){
        scanf("%d",&n);
        int ans=n;
        for (int i=1;i<=n/2;i++){
            int left=n-i*2;
            ans=max(ans,left*(i+1));
        }
        printf("%d\n",ans);
    }
}
