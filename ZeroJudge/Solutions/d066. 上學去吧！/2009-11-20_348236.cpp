#include <iostream>
using namespace std;
int main()
{
    int hh,mm;
    while (cin>>hh>>mm)
    {
        if (hh>=7&&mm>=30&&hh<17)
            cout<<"At School"<<endl;
        else if (hh>=8&&hh<17)
            cout<<"At School"<<endl;
        else
            cout<<"Off School"<<endl;
    }
    system("pause");
    return 0;
}
