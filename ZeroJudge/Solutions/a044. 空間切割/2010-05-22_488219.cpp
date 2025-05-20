#include <iostream>
using namespace std;

int main()
{
    int b=2,a;
    while (cin>>a)
    {
        for (int i=1;i<a;i++)
        {
            b+=(i*i+i+2)/2;
        }
        cout<<b<<endl;
        b=2;
    }
    //system("pause");
    return 0;
}
