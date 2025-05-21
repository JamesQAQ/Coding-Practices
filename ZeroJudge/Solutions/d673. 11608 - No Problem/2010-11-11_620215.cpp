#include <iostream>
using namespace std;

int main()
{
    int sum,a[12],b[12],x=0;
    while (cin>>sum)
    {
        x++;
        if (sum<0)
            break;
        for (int i=0;i<12;i++)
            cin>>a[i];
        for (int i=0;i<12;i++)
            cin>>b[i];
        cout<<"Case "<<x<<":"<<endl;
        for (int i=0;i<12;i++)
        {
            if (sum>=b[i])
            {
                sum-=b[i];
                cout<<"No problem! :D"<<endl;
            }
            else
                cout<<"No problem. :("<<endl;
            sum+=a[i];
        }
    }
    return 0;
}
