#include <cstdio>
#include <algorithm>

struct Node {int v;char c;} a[3];
bool cmp(Node i,Node j){
    return i.v<j.v;
}
int main()
{
    while (scanf("%d %d %d",&a[0].v,&a[1].v,&a[2].v)==3){
        for (int i=0;i<3;i++)
            a[i].c=i+'A';
        std::stable_sort(a,a+3,cmp);
        putchar((a[1].v>a[2].v-a[0].v)?a[1].c:a[2].c);
        puts("");
    }
}
