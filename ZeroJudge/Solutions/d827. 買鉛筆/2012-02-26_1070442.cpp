#include <cstdio>

int main()
{
    int n;
    while (scanf("%d",&n)==1)
        printf("%d\n",(n/12)*50+(n%12)*5);
}
