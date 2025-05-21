#include <cstdio>

int main()
{
    int n;
    while (scanf("%d",&n)==1)
        printf("%d\n",((n>40)?100:(n>20)?80+n-20:(n>10)?60+2*(n-10):n*6));
    return 0;
}
