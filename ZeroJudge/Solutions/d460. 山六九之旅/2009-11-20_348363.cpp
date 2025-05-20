#include <iostream>
using namespace std;
int main()
{
    int y;
    while (cin>>y)
    {
        if (y>=60)
        cout<<399<<endl;
        else if (y>=18)
        cout<<890<<endl;
        else if (y>=12)
        cout<<790<<endl;
        else if (y>=6)
        cout<<590<<endl;
        else
        cout<<0<<endl;
    }
    system("pause");
    return 0;
}
