#include <iostream>
using namespace std;

int main()
{
    bool n;
    string s;
    int a[3];
    while (cin>>s)
    {
        n=0;
        memset(a,0,sizeof(a));
        int len=s.length();
        if (s[0]=='-')
        {
            n=1;
            a[0]=s[1]-48;
            if (len>3)
                a[1]=s[3]-48;
            if (len>4)
                a[2]=s[4]-48;
            if (s[5]>='5')
                a[2]++;
            if (a[2]>9)
            {
                a[2]=0;
                a[1]++;
            }
            if (a[1]>9)
            {
                a[1]=0;
                a[0]++;
            }
        }
        else
        {
            a[0]=s[0]-48;
            if (len>3)
                a[1]=s[2]-48;
            if (len>4)
                a[2]=s[3]-48;
            if (s[4]>='5')
                a[2]++;
            if (a[2]>9)
            {
                a[2]=0;
                a[1]++;
            }
            if (a[1]>9)
            {
                a[1]=0;
                a[0]++;
            }
        }
        if (a[0]==0&&a[1]==0&&a[2]==0)
            cout<<"0.00"<<endl;
        else if (n) 
            cout<<"-"<<a[0]<<"."<<a[1]<<a[2]<<endl;
        else
            cout<<a[0]<<"."<<a[1]<<a[2]<<endl;
    }
    return 0;
}
