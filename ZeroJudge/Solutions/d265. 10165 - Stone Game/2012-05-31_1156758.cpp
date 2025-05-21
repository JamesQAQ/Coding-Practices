#include <cstdio>

int main()
{
    int n;
    while (scanf("%d",&n),n){
        int tmp,x;
        scanf("%d",&x);
        for (int i=1;i<n;i++)
            scanf("%d",&tmp),x^=tmp;
        puts((x==0)?"No":"Yes");
    }
}
