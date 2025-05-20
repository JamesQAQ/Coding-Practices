#include <iostream>
using namespace std;

int main()
{
    int num[256],n;
    string s;
    bool fail;
    while (cin>>n)
    {
        getline(cin,s);
        for (int i=0;i<n;i++)
        {
            fail=0;
            getline(cin,s);
            memset(num,0,sizeof(num));
            int len=s.length();
            for (int i=0;i<len;i++)
                num[s[i]]++;
            getline(cin,s);
            for (int i=0;i<len;i++)
            {
                num[s[i]]--;
                if (num[s[i]]<0)
                {
                    fail=1;
                    break;
                }
            }
            if (fail)
                cout<<"impossible"<<endl;
            else
                cout<<"possible"<<endl;
        }
    }
    return 0;
}
