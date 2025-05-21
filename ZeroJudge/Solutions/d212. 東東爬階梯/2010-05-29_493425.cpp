#include <iostream>
using namespace std;

int main()
{
    long long int a[100]={1,2};
    int n;
    for (int i=2;i<100;i++)
        a[i]+=a[i-1]+a[i-2];
    while (cin>>n)
    {
        cout<<a[n-1]<<endl;
    }
    //system("pause");
    return 0;
}
