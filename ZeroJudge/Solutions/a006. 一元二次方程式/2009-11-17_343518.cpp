#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    double a,b,c;
    while (cin>>a>>b>>c)
    {
        if (b*b-4*a*c>0)
        cout<<"Two different roots x1="<<(-b+sqrt(b*b-4*a*c))/(2*a)<<" , x2="<<(-b-sqrt(b*b-4*a*c))/(2*a)<<endl;
        else if (b*b-4*a*c==0)
        cout<<"Two same roots x="<<(-b+sqrt(b*b-4*a*c))/(2*a)<<endl;
        else if (b*b-4*a*c<0)
        cout<<"No real root"<<endl;
    }
    system("pause");
    return 0;
}
