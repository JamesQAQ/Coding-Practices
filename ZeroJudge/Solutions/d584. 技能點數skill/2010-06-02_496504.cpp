#include <iostream>
using namespace std;

int main()
{
    int career,lv;
    while (cin>>career>>lv)
    {
        if (career==0)
            cout<<0<<endl;
        else if (career==2)
        {
            if (lv<8)
                cout<<0<<endl;
            else if (lv<30)
                cout<<1+(lv-8)*3<<endl;
            else if (lv<70)
                cout<<2+(lv-8)*3<<endl;
            else if (lv<120)
                cout<<3+(lv-8)*3<<endl;
            else
                cout<<6+(lv-8)*3<<endl;
        }
        else
        {
            if (lv<10)
                cout<<0<<endl;
            else if (lv<30)
                cout<<1+(lv-10)*3<<endl;
            else if (lv<70)
                cout<<2+(lv-10)*3<<endl;
            else if (lv<120)
                cout<<3+(lv-10)*3<<endl;
            else
                cout<<6+(lv-10)*3<<endl;
        }
    }
    //system("pause");
    return 0;
}
