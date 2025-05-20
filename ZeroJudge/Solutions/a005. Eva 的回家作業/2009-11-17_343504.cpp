#include <iostream>
using namespace std;
int main()
{
    int i,t,a,b,c,d,r,dd;
    while (cin >> t)
    for (i=1;i<=t;i++)
    {
        cin>>a>>b>>c>>d;
        r=b/a;
        dd=b-a;
        if (b/a==c/b)
            cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<d*r<<endl;
        else
            cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<d+dd<<endl;
    }
    system("pause");
    return 0;
}
