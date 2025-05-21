#include <iostream>
using namespace std;

int main()
{
    int a[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int y,m,d,day=0;
    while (cin>>y>>m>>d)
    {
        a[1]=28;
        if (y%400==0)
            a[1]=29;
        else if (y%100==0)
            a[1]=28;
        else if (y%4==0)
            a[1]=29;
        if ((m>=13)||(d>a[m-1])||(d<=0)||(m<=0)||(y<=0))
        {
            cout<<"Error"<<endl;
            continue;
        }
        for (int i=0;i<m-1;i++)
            day+=a[i];
        day+=d;
        if (day==1)
            cout<<"It is "<<day<<" day in "<<y<<endl;
        else
            cout<<"It is "<<day<<" days in "<<y<<endl;
        day=0;
    }
    //system("pause");
    return 0;
}
