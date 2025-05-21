#include <cstdio>
#include <algorithm>

struct Node {int h,w,o;} a[20000];
bool cmp(Node i,Node j){
    if (i.h<j.h)
        return true;
    if (i.h>j.h)
        return false;
    if (i.w<j.w)
        return true;
    if (i.w>j.w)
        return false;
    return i.o<j.o;
}
int Abs(int x){
    return (x<0)?-x:x;
}
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        scanf("%d %d",&a[i].h,&a[i].w),a[i].o=i;
    std::stable_sort(a,a+n,cmp);
    int ans=0;
    for (int i=0;i<n;i++)
        ans+=Abs(a[i].o-i);
    printf("%d\n",ans);
}
