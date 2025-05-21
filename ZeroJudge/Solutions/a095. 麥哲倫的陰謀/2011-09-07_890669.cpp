#include <cstdio>

int main()
{
    unsigned int n,m;
    while (scanf("%u %u",&n,&m)==2)
        printf("%u\n",(n<m+1)?n:m+1);
    return 0;
}
