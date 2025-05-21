#include <iostream>
using namespace std;

int main()
{
    string s;
    int n;
    while (getline(cin,s))
    {
        n=s.length();
        for (int i=0;i<n;i++)
        {
            if ((s[i]<=90)&&(s[i]>=65)||(s[i]<=122)&&(s[i]>=97))
                cout<<s[i];
        }
        s.clear();
    }
    //system("pause");
    return 0;
}
