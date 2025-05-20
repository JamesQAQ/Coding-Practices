#include <iostream>
using namespace std;

int main()
{
    int n,a,b,sum;
    while (cin>>n)
    {
        if (n==0)
            break;
        sum=0;
        cin>>a;
        for (int i=1;i<n;i++)
        {
            cin>>b;
            if (a>b)
                sum+=(a-b)*10;
            else
                sum+=(b-a)*20;
            a=b;
        }
        cout<<sum<<endl;
    }
    return 0;
}
