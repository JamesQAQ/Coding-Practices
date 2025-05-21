#include <iostream>
using namespace std;

int main()
{
    string s;
    long long ans;
    int len;
    char c[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    while (getline(cin,s))
    {
        if (s=="#")
            break;
        len=s.length();
        ans=0;
        if (len%2)
        {
            ans+=s[0];
            len--;
            s.erase(0,1);
        }
        for (int i=0;i<len;i+=2)
        {
            ans*=65536;
            ans%=34943;
            ans+=s[i]*256+s[i+1];
        }
        ans*=65536;
        ans%=34943;
        if (ans!=0)
            ans=34943-ans;
        cout<<c[ans/4096];
        ans%=4096;
        cout<<c[ans/256]<<" ";
        ans%=256;
        cout<<c[ans/16];
        ans%=16;
        cout<<c[ans]<<endl;
    }
    return 0;
}
