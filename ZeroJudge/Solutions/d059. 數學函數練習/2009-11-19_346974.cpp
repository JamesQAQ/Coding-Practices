#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
    double a,b;
    double c;
    int d,e,f;
    while (cin>>a>>b)
    {
        cout<<pow(a,b)<<endl;
        cin>>c;
        cout<<fixed<<setprecision(3)<<sqrt(c)<<endl;
        cin>>d;
        if (d>=0)
        cout<<d<<endl;
        else
        cout<<-d<<endl;
        cin>>e>>f;
        cout<<rand()%f+e<<endl;
    }
    system("pause");
    return 0;
}
