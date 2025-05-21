#include <cstdio>

int main()
{
    int n,m;
    while (scanf("%d %d",&n,&m)==2)
        puts((n^m)?">\\\\\\<":"= =\"");
}
