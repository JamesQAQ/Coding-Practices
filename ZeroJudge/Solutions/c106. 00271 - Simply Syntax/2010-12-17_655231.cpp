#include <iostream>
using namespace std;

string s;
int len;

bool test(int x)
{
    if (s[x]=='N')
    {
        if (len>x+1)
        {
            if (test(x+1))
            {
                s[x]='p';
                s.erase(x+1,1);
                len--;
                if (x==0&&len!=1)
                    return 0;
                return 1;
            }
            return 0;
        }
        else
            return 0;
    }
    else if (s[x]<90)
    {
        if (len>x+2)
        {
            if (test(x+1)&&test(x+2))
            {
                s[x]='p';
                s.erase(x+1,2);
                len-=2;
                if (x==0&&len!=1)
                    return 0;
                return 1;
            }
            return 0;
        }
        else
            return 0;
    }
    else
    {
        if (x==0&&len!=1)
            return 0;
        return 1;
    }
}
bool fail()
{
    for (int i=0;i<len;i++)
        if (s[i]>'z'||(s[i]<'p'&&!(s[i]=='N'||s[i]=='C'||s[i]=='D'||s[i]=='E'||s[i]=='I')))
            return 1;
    return 0;
}
int main()
{
    while (cin>>s)
    {
        len=s.length();
        if (fail())
            cout<<"NO"<<endl;
        else
            cout<<(test(0)?"YES":"NO")<<endl;
    }
    return 0;
}
