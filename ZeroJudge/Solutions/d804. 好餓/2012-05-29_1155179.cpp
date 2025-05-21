#include <cstdio>
#include <algorithm>

int a[100000];
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for (int i=0;i<n;i++)
        scanf("%d",&a[i]);
    std::stable_sort(a,a+n);
    int sum=0,cnt=0;
    for (int i=n-1;i>=0;i--){
        if (sum>=m)
            break;
        sum+=a[i],cnt++;
    }
    if (sum<m)
        puts("OAQ");
    else    
        printf("%d\n",cnt);
}
