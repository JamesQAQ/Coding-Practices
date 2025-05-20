#include <iostream>
using namespace std;
int main()
{
    int n;
    while (cin>>n)
    {
        long s[n];
        for (int i=1;i<=n;i++)
        {
            cin>>s[i];
            cout<<"Case "<<i<<": ";
            if (s[i]%400==0)
                cout<<"a leap year"<<endl;
            else if (s[i]%100==0)
                cout<<"a normal year"<<endl;
            else if (s[i]%4==0)
                cout<<"a leap year"<<endl;
            else
                cout<<"a normal year"<<endl;
        }
    }
    system("pause");
    return 0;
}
