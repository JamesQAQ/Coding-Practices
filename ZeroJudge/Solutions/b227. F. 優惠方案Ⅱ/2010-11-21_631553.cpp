#include <iostream>
using namespace std;

int main()
{
    int n,a,b,sum1,sum2;
    while (cin>>n)
        while (n-->0)
        {
            cin>>a>>b;
            sum1=(a%2)?(a-1)*b*800+1000*b:a*b*800;
            sum1=(sum1%1000)?sum1/1000+1:sum1/1000;
            sum2=a*b*812;
            sum2=(sum2%1000)?sum2/1000+1:sum2/1000;
            if (sum1<sum2)
                cout<<": )"<<endl;
            else if (sum1>sum2)
                cout<<"8-12=-4"<<endl;
            else
                cout<<"SAME"<<endl;
        }
    return 0;
}
