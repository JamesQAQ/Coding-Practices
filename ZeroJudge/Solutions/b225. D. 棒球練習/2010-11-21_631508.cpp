#include <iostream>
using namespace std;

int main()
{
    int x1,y1,x2,y2,x3,y3,n;
    while (cin>>n)
        while (n-->0)
        {
            cin>>x1>>y1>>x2>>y2>>x3>>y3;
            if ((x1-x2)*(y2-y3)==(x2-x3)*(y1-y2))
                cout<<"NO"<<endl;
            else
                cout<<"YES"<<endl;
        }
    return 0;
}
