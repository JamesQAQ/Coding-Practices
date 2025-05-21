#include <iostream>
using namespace std;

int main()
{
    int a,b;
    while (cin>>a>>b)
    {
        a=(a%2==1)?(a-1)/2:(a-2)/2;
        b=(b%2==1)?(b-1)/2:b/2;
        printf("%d",b-a);
        printf("\n");
    }
    //system("pause");
    return 0;
}
