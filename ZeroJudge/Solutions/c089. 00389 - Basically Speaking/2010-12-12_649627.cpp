#include <iostream>
using namespace std;

int ans[8],num,v[100],n,in,out;
char s[16];
bool change()
{
    num=0;
    while (n!=0)
    {
        ans[num++]=n%out;
        n/=out;
        if (num==8)
            return 0;
    }
    return 1;
}
int main()
{
    for (int i=0;i<10;i++)
    {
        v[i+'0']=i;
        s[i]=i+'0';
    }
    for (int i=0;i<6;i++)
    {
        v[i+'A']=i+10;
        s[i+10]=i+'A';
    }
    string x;
    while (cin>>x>>in>>out)
    {
        int len=x.length();
        n=0;
        for (int i=0;i<len;i++)
            n=n*in+v[x[i]];
        if (change())
        {
            if (num==0)
                cout<<"      0"<<endl;
            else
            {
                for (int i=0;i<7-num;i++)
                    cout<<" ";
                for (int i=num-1;i>=0;i--)
                    cout<<s[ans[i]];
                cout<<endl;
            }
        }
        else
            cout<<"  ERROR"<<endl;
    }
    return 0;
}
