#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n,i;
    double m;
    cout.setf(ios::fixed);
    cout.precision(0);
    while (cin>>n>>m)
    {
        i=m*log10(n);
        cout<<i+1<<endl;
    }
    //system("pause");
    return 0;
}
