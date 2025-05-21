#include <iostream>
using namespace std;

int main()
{
    int a,b,sum=0;
    while (cin>>a>>b)
    {
        a=(a%4==0)?a:a+4-a%4;
        b=(b%4==0)?b:b-b%4;
        sum+=(b-a)/4+1;
        for (int i=1700;i<=b;i+=100)
            if (i>=a)
                sum--;
        for (int i=1600;i<=b;i+=400)
            if (i>=a)
                sum++;
        cout<<sum<<endl;
        sum=0;
    }
    //system("pause");
    return 0;
}
