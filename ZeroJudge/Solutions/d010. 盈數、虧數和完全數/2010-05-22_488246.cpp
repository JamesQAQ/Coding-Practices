#include <iostream>
using namespace std;

int main()
{
    int a,sum=0;
    while (cin>>a)
    {
        for (int i=1;i<a;i++)
        {
            if (a%i==0)
            {
                sum+=i;
            }
        }
        if (a<sum)
            cout<<"盈數"<<endl;
        else if (a==sum)    
            cout<<"完全數"<<endl;
        else if (a>sum)    
            cout<<"虧數"<<endl;
        sum=0;
    }
    //system("pause");
    return 0;
}
