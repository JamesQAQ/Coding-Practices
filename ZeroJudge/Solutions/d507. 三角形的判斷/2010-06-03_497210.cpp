#include <iostream>
using namespace std;

int main()
{
    int a,b,c;
    while (cin>>a>>b>>c)
    {
        if ((a*a+b*b==c*c)||(a*a+c*c==b*b)||(c*c+b*b==a*a))
            cout<<"right triangle"<<endl;
        else if ((a*a+b*b<c*c)||(a*a+c*c<b*b)||(c*c+b*b<a*a))
            cout<<"obtuse triangle"<<endl;
        else
            cout<<"acute triangle"<<endl;
    }
    //system("pause");
    return 0;
}
