#include <iostream>
using namespace std;

int main()
{
    string s;
    bool c=0;
    while (getline(cin,s))
    {
        int n=s.length();
        for (int i=0;i<n;i++)
        {
            if (s[i]=='"')
            {
                if (c==0)
                {
                    cout<<"``";
                    c=1;
                }
                else
                {
                    cout<<"''";
                    c=0;
                }
            }
            else
                cout<<s[i];
        }
        cout<<endl;
    }
    //system("pause");
    return 0;
}
