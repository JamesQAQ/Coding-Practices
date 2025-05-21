#include <iostream>
using namespace std;

int main()
{
    double F;
    while (cin>>F)
    {
        cout.setf(ios::fixed);
        cout.precision(3);
        cout<<(F-32)/9*5<<endl;
    }
    //system("pause");
    return 0;
}
