#include <iostream>
using namespace std;
int main()
{
    long long int x,i,m=1;
    while (cin>>x)
    {
        if (x==0)
        cout<<1<<endl;
        else
        {
        for (i=1;i<=x;i++)
        m *=i;
        cout<<m<<endl;
        m=1;
        }
    }
    system("pause");
    return 0;
}
