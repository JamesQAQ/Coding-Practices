#include <cmath>
#include <cstdio>

int main()
{
    int n;
    while (scanf("%d",&n),n){
        int t=(int)sqrt(n);
        if (t*t==n)
            puts("yes");
        else
            puts("no");
    }
}
