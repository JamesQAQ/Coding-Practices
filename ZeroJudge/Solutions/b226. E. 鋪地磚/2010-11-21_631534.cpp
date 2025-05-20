#include <iostream>
using namespace std;

int main()
{
    int a,b,c,d;
    while (cin>>a>>b>>c>>d)
    {
        if (a==0&&b==0&&c==0&&d==0)
            break;
        if (a%c==0&&b%d==0)
            cout<<a/c*b/d<<endl;
        else if (a%d==0&&b%c==0)
            cout<<a/d*b/c<<endl;
        else
            cout<<"-1"<<endl;
    }
    return 0;
}
