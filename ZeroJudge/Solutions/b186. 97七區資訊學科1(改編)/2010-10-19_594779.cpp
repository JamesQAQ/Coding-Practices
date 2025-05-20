#include <iostream>
using namespace std;

int main()
{
    int ck,cc,ca;
    while (cin>>ck>>cc>>ca)
    {
        int free=min(ck/10,ca/2);
        printf("%d 個餅乾，%d 盒巧克力，%d 個蛋糕。\n",ck,cc+free,ca);
    }
    return 0;
}
