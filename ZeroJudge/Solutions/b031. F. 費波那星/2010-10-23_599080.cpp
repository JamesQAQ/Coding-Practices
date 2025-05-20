#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    short a[1002],maxlen;
    string s;
    bool check;
    while (cin>>s)
    {
        int len=s.length();
        maxlen=len;
        if (len==1&&s[0]=='0')
            break;
        memset(a,0,sizeof(a));
        for (int i=0;i<len;i++)
            a[i]=s[i]-48;
        cin>>s;
        len=s.length();
        for (int i=0;i<len;i++)
            a[i]+=s[i]-48;
        if (len>maxlen)
            maxlen=len;
        check=1;
        while (check)
        {
            check=0;
            for (int i=0;i<maxlen;i++)
            {
                if (a[i]==1&&a[i+1]==1)
                {
                    a[i]=0;
                    a[i+1]=0;
                    a[i+2]++;
                    if (i+3>maxlen)
                        maxlen=i+3;
                    check=1;
                }
                else if (a[i]==2)
                {
                    if (i>=2)
                    {
                        a[i]=0;
                        a[i+1]++;
                        a[i-2]++;
                        if (i+2>maxlen)
                            maxlen=i+2;
                    }
                    else if (i==0)
                    {
                        a[i]=0;
                        a[i+1]++;
                        if (i+2>maxlen)
                            maxlen=i+2;
                    }
                    else if (i==1)
                    {
                        a[i]=0;
                        a[i-1]++;
                        a[i+1]++;
                        if (i+2>maxlen)
                            maxlen=i+2;
                    }
                    check=1;
                }
                else if (a[i]==3)
                {
                    a[i]=1;
                    a[i+2]++;
                    a[i-1]++;
                    if (i+3>maxlen)
                        maxlen=i+3;
                    check=1;
                }
            }
        }
        for (int i=0;i<maxlen;i++)
            cout<<a[i];
        cout<<endl;
    }
    return 0;
}
