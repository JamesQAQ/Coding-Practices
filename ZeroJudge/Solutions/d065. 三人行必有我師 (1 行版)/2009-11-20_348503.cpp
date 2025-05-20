#include <iostream>
using namespace std;
int main()
{
    int a,b,c,max=0;
    while (cin>>a)
    {
        if (a>max)
            max=a;
        cin>>b;
        if (b>max)
            max=b;
        cin>>c;
        if (c>max)
            max=c;
        cout<<max<<endl;
        max=0;
    }
    system("pause");
    return 0;
}
