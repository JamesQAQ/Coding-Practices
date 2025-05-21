#include <iostream>
using namespace std;

int main()
{
    int t;
    while (cin>>t)
    {
        if (t>=15)
            cout<<t-15<<endl;
        else
            cout<<t+9<<endl;
    }
    //system("pause");
    return 0;
}
