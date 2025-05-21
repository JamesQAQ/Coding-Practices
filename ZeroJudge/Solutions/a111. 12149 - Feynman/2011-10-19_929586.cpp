#include <cstdio>

int main()
{
    int n;
    while (scanf("%d",&n),n)
        printf("%d\n",n*(n+1)*(n+n+1)/6);
    return 0;
}
