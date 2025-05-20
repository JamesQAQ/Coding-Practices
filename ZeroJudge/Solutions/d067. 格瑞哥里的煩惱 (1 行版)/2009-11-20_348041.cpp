#include <iostream>
using namespace std;
int main()
{
    int y;
    while (cin>>y)
    {
    if (y%400==0)
        cout<<"a leap year"<<endl;
    else if (y%100==0)
        cout<<"a normal year"<<endl;
    else if (y%4==0)
        cout<<"a leap year"<<endl;
    else
        cout<<"a normal year"<<endl; 
    }
    system("pause");
    return 0;
}
