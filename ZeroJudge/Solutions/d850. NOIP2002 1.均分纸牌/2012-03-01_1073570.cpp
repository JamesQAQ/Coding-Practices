#include <cstdio>

int main()
{
    int n,a[100];
    while (scanf("%d",&n)==1){
        int sum=0,s=0,l=0;
        for (int i=0;i<n;i++)
            scanf("%d",&a[i]),sum+=a[i];
        sum/=n;
        int ans=0;
        for (int i=0;i<n-1;i++)
            if (a[i]!=sum){
                a[i+1]+=a[i]-sum;
                ans++;
            }
        printf("%d\n",ans);
    }
}
