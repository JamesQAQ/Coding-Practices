#include <iostream>
using namespace std;

int main()
{
    string s;
    while (cin>>s)
    {
        int a=s.length();
        int n=a-1;
        if (s[n]==48)
        {
            n--;
            while (s[n]==48)
                n--;
        }
        for (int i=n;i>-1;i--)
            cout<<s[i];
        cout<<endl;
    }
    system ("pause");
    return 0;
}
