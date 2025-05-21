#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

int main()
{
    cout.setf(ios::fixed);
    cout.precision(2);
    cout.fill('0');
    int a,b;
    char c;
    string s;
    while (cin>>s)
    {
        stringstream ss(s);
        ss>>a>>c>>b;
        a=a*100+b;
        if (a<10000)
        {
            a*=9;
            a/=10;
            a+=800;
            cout<<"$"<<a/100<<"."<<setw(2)<<a%100<<endl;
        }
        else if (a==10000)
            cout<<"$90.00"<<endl;
        else if (a<=50000)
        {
            a*=4;
            a/=5;
            cout<<"$"<<a/100<<"."<<setw(2)<<a%100<<endl;
        }
        else
        {
            a*=3;
            a/=5;
            cout<<"$"<<a/100<<"."<<setw(2)<<a%100<<endl;
        }
    }
    return 0;
}
