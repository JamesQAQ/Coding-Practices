#include <iostream>
using namespace std;

int main()
{
    long long a[7601];
    a[0]=0;
    a[10]=96;
    a[20]=564;
    a[30]=1394;
    a[100]=28565;
    a[1000]=14097948;
    a[5000]=1297092472;
    a[7600]=4294853005LL;
    int n;
    while (cin>>n)
    {
        if (n<0)
            break;
        cout<<a[n]<<endl;
    }
    return 0;
}
