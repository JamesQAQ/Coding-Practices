#include <iostream>
using namespace std;
int main()
{
    int x;
    while (cin>>x)
    {
        if (x%2==0)
            cout<<"Even"<<endl;
        else 
            cout<<"Odd"<<endl;   
    }
    system("pause");
    return 0;
}
