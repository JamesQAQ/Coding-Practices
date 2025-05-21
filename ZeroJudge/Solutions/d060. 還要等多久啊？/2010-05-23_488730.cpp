#include <iostream>
using namespace std;

int main()
{
    int t;
    while (cin>>t)
    {
        if (t<=25)
            cout<<25-t<<endl;
        else
            cout<<85-t<<endl;
    }
    //system("pause");
    return 0;
}
