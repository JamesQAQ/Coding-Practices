#include <iostream>
using namespace std;

int main()
{
    unsigned long long n=3,k=2,l=1,r=3;
    int t=0;
    while (t<10)
    {
        while (l+k<=r-k-1)
        {
            l+=k;
            r-=k+1;
            k++;;
        }
        if (l==r)
        {
            t++;
            printf("%10u",k);
            printf("%10u\n",n);
        }
        n++;
        r+=n;
    }
    //system("pause");
    return 0;
}
