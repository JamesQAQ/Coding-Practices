#include <iostream>
using namespace std;

int main()
{
    int a,b;
    while (cin>>a>>b)
    {
        if (a==0&&b==0)
            break;
        int la=0,lb=1,ma=1,mb=1,ra=1,rb=0;
        double goal=(double)a/b;
        while (ma!=a||mb!=b)
        {
            if (((double)ma/mb)>goal)
            {
                cout<<"L";
                ra=ma;
                rb=mb;
                ma=ra+la;
                mb=rb+lb;
            }
            else
            {
                cout<<"R";
                la=ma;
                lb=mb;
                ma=ra+la;
                mb=rb+lb;
            }
        }
        cout<<endl;
    }
    return 0;
}
