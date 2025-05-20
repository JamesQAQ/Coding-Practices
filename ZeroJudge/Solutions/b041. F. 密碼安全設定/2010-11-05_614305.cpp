#include <iostream>
using namespace std;

string a,b,temp="~!@#$%^&*()_+|`-=\\{}[]:\";\'<>?,./ ";
int len;
bool bigE()
{
    for (int i=0;i<len;i++)
        if (a[i]<='Z'&&a[i]>='A')
            return 0;
    return 1;
}
bool smallE()
{
    for (int i=0;i<len;i++)
        if (a[i]<='z'&&a[i]>='a')
            return 0;
    return 1;
}
bool number()
{
    for (int i=0;i<len;i++)
        if (a[i]<=59&&a[i]>=48)
            return 0;
    return 1;
}
bool special()
{
    for (int i=0;i<len;i++)
        if (temp.find(a[i])!=-1)
            return 0;
    return 1;
}
bool symmetric()
{
    for (int i=0;i<len/2;i++)
        if (a[i]!=a[len-i-1])
            return 0;
    return 1;
}
bool cycle()
{
    int p,llen;
    for (int i=3;i<=6;i++)
    {
        if (i>=len)
            break;
        b=a;
        llen=len;
        string c=a.substr(0,i);
        p=b.find(c);
        while (p==0&&llen!=0)
        {
            if (llen>=i)
                b.erase(0,i);
            else
                b.erase(0,llen);
            llen=b.length();
            if (llen<i)
                c=c.substr(0,llen);
            p=b.find(c);
        }
        if (llen==0)
            return 1;
    }
    return 0;
}
int main()
{
    while (getline(cin,a))
    {
        getline(cin,b);
        if (a=="END"&&b=="END")
            break;
        len=a.length();
        if (a!=b)
            cout<<"Password settings are not consistent."<<endl;
        else if (len<8||len>12)
            cout<<"Password should contain 8 to 12 characters."<<endl;
        else if (bigE())
            cout<<"Password should contain at least one upper-case alphabetical character."<<endl;
        else if (smallE())
            cout<<"Password should contain at least one lower-case alphabetical character."<<endl;
        else if (number())
            cout<<"Password should contain at least one number."<<endl;
        else if (special())
            cout<<"Password should contain at least one special character."<<endl;
        else if (symmetric())
            cout<<"Symmetric password is not allowed."<<endl;
        else if (cycle())
            cout<<"Circular password is not allowed."<<endl;
        else
            cout<<"Password is valid."<<endl;
    }
    return 0;
}
