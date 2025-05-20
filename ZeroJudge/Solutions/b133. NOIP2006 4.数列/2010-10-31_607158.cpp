#include <iostream>
using namespace std;

int k;
int poww(int x)
{
    int d=1;
    for (int i=0;i<x;i++)
        d*=k;
    return d;
}
int main()
{
    int n;
    bool use[10];
    while (cin>>k>>n)
    {
        memset(use,0,sizeof(use));
        for (int i=0;i<10;i++)
        {
            use[i]=n%2;
            n/=2;
        }
        int sum=0;
        for (int i=0;i<10;i++)
            if (use[i])
                sum+=poww(i);
        cout<<sum<<endl;
    }
    return 0;
}
