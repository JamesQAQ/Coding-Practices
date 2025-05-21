#include <iostream>
using namespace std;

int main()
{
    int a;
    while(cin>>a)
    {
        if (a%400==0)
            cout<<"a leap year"<<endl;
        else if (a%100==0)
            cout<<"a normal year"<<endl;
        else if (a%4==0)
            cout<<"a leap year"<<endl;
        else
            cout<<"a normal year"<<endl;
    }
    //system("pause");
    return 0;
}
