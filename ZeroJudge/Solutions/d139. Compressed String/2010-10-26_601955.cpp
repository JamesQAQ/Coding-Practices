#include <iostream>
using namespace std;

int main()
{
    string s;
    int sum;
    char c;
    while (cin>>s)
    {
        sum=0;
        c=s[0];
        int len=s.length();
        for (int i=0;i<len;i++)
        {
            if (s[i]==c)
                sum++;
            else
            {
                if (sum>2)
                    cout<<sum;
                else if (sum==2)
                    cout<<c;
                sum=1;
                cout<<c;
                c=s[i];
            }
        }
        if (sum>0)
        {
            if (sum>2)
                cout<<sum;
            else if (sum==2)
                cout<<c;
            cout<<c;
        }
        cout<<endl;
    }
    return 0;
}
