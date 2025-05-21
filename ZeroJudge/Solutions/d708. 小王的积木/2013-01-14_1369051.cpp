#include <cstdio>

unsigned int input(){
    char c=getchar();
    while (c>'9'||c<'0') c=getchar();
    unsigned int x=c-48;c=getchar();
    while (c<='9'&&c>='0') x=x*10+c-48,c=getchar();
    return x;
}
int main()
{
    int n;
    scanf("%d",&n);
    unsigned int x=0;
    n--;
    while (n--)
        x^=input();
    printf("%u\n",x);
}
