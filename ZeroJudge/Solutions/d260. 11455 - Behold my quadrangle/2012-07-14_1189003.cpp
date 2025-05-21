#include <cstdio>
#include <algorithm>

int main()
{
    int cases,a[4];
    scanf("%d",&cases);
    while (cases--){
        for (int i=0;i<4;i++)
            scanf("%d",&a[i]);
        std::stable_sort(a,a+4);
        if (a[0]==a[1]&&a[2]==a[3]){
            if (a[1]==a[2])
                puts("square");
            else
                puts("rectangle");
        }
        else if (a[0]+a[1]+a[2]>a[3])
            puts("quadrangle");
        else
            puts("banana");
    }
}
