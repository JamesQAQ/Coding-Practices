#include <iostream>
using namespace std;
int main()
{
    string s;
    int m=0,n;
    while (cin>>s)
    {
        n=s.length();
        for (int i=0;i<n;i++)
            m +=s[i];
        if (m%3==0)
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
        m=0;
    }
    system("pause");
    return 0;
}
