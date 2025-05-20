#include <iostream>
using namespace std;

int main()
{
    int a,b;
    while (cin>>a)
    {
        if (a==0)
            break;
        b=1;
        for (int i=2;i*i<=a;i++)
            if (a%i==0)
            {
                b+=i;
                b+=a/i;
                if (i*i==a)
                    b-=i;
            }
        if (a==b)
        {
            cout<<"="<<a<<endl;
            continue;
        }
        int sum=1;
        for (int i=2;i*i<=b;i++)
            if (b%i==0)
            {
                sum+=i;
                sum+=b/i;
                if (i*i==b)
                    sum-=i;
            }
        if (sum==a)
            cout<<b<<endl;
        else
            cout<<"0"<<endl;
    }
    return 0;
}
