#include <cstdio>

int stack[100000],top=0;
int main()
{
    int n,w,h,ans=0;
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%d %d",&w,&h);
        while (top&&stack[top-1]>h)
            ans++,top--;
        if (top==0||stack[top-1]!=h)
            stack[top++]=h;
    }
    ans+=top;
    printf("%d\n",ans);
}
