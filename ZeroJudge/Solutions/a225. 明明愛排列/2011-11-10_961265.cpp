#include <cstdio>
#include <algorithm>

bool cmp(int i,int j){
    if (i%10<j%10)
        return true;
    if (i%10>j%10)
        return false;
    return i>j;
}
int main()
{
    int n,a[1000];
    while (scanf("%d",&n)==1){
        for (int i=0;i<n;i++)
            scanf("%d",&a[i]);
        std::stable_sort(a,a+n,cmp);
        for (int i=0;i<n;i++)
            printf((i)?" %d":"%d",a[i]);
        puts("");
    }
    return 0;
}
