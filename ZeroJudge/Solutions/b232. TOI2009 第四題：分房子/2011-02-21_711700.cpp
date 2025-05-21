#include <iostream>
using namespace std;

int main()
{
    long long a[751]={1},n,m;
    for (int i=1;i<750;i+=2)
        for (int j=i;j<=750;j++)
            a[j]+=a[j-i];
    while (cin>>m)
        while (m-->0)
        {
            cin>>n;
            cout<<a[n]<<endl;
        }
    return 0;
}
