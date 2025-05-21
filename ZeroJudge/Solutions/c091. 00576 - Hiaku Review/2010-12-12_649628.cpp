#include <iostream>
using namespace std;

bool m[123]={};

bool test(string s,int d)
{
    int sum=0,len=s.length();
    for (int i=0;i<len;i++)
        if (m[s[i]])
        {
            sum++;
            if (sum>d)
                return 0;
            i++;
            while (m[s[i]]&&i<len)
                i++;
        }
    if (sum==d)
        return 1;
    return 0;
}

int main()
{
    m['a']=1;
    m['e']=1;
    m['i']=1;
    m['o']=1;
    m['u']=1;
    m['y']=1;
    string s,temp;
    int p;
    while (getline(cin,s))
    {
        if (s=="e/o/i")
            break;
        p=s.find("/");
        temp=s.substr(0,p);
        s.erase(0,p+1);
        if (!test(temp,5))
        {
            cout<<"1"<<endl;
            continue;
        }
         p=s.find("/");
        temp=s.substr(0,p);
        s.erase(0,p+1);
        if (!test(temp,7))
        {
            cout<<"2"<<endl;
            continue;
        }
        if (!test(s,5))
        {
            cout<<"3"<<endl;
            continue;
        }
        cout<<"Y"<<endl;
    }
    return 0;
}
