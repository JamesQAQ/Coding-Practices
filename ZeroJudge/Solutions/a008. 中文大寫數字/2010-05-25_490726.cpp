#include <iostream>
using namespace std;

void coutchi (int a);
int main()
{
    int n,a,b,c,m1,m2,m3,a0,b0;
    while (cin>>n)
    {
        a=n/100000000;
        n%=100000000;
        b=n/10000;
        n%=10000;
        c=n;
        a0=a;
        b0=b;
        if (a>0)
        {
            m3=a/10;
            a%=10;
            if (m3>0)
            {
                coutchi (m3);
                cout<<"拾";
            }
            if (a>0)
                coutchi (a);
            cout<<"億";
        }
        if (b==0)
        {
            if ((a0>0)&&(c>0))
                cout<<"零";
        }
        else
        {
            m1=b/1000;
            b%=1000;
            m2=b/100;
            b%=100;
            m3=b/10;
            b%=10;
            if (m1>0)
            {
                coutchi (m1);
                cout<<"仟";
            }
            else if ((a0>0)&&((m2!=0)||(m3!=0)||(b!=0)))
                cout<<"零";
            if (m2>0)
            {
                coutchi (m2);
                cout<<"佰";
            }
            else if ((m1>0)&&((b>0)||(m3>0)))
                cout<<"零";
            if (m3>0)
            {
                coutchi (m3);
                cout<<"拾";
            }
            else if ((m2>0)&&(b>0))
                cout<<"零";
            if (b>0)
                coutchi (b);
            cout<<"萬";
        }
        if ((c==0)&&(a0==0)&&(b0==0))
            cout<<"零"<<endl;
        else
        {
            m1=c/1000;
            c%=1000;
            m2=c/100;
            c%=100;
            m3=c/10;
            c%=10;
            if (m1>0)
            {
                coutchi (m1);
                cout<<"仟";
            }
            else if (((b0>0)||((a0>0)&&(b0!=0)))&&((m2!=0)||(m3!=0)||(c!=0)))
                cout<<"零";
            if (m2>0)
            {
                coutchi (m2);
                cout<<"佰";
            }
            else if ((m1>0)&&((c>0)||(m3>0)))
                cout<<"零";
            if (m3>0)
            {
                coutchi (m3);
                cout<<"拾";
            }
            else if ((m2>0)&&(c>0))
                cout<<"零";
            if (c>0)
                coutchi (c);
            cout<<endl;
        }
    }
    //system("pause");
    return 0;
}

void coutchi (int a)
{
    if (a==1)
        cout<<"壹";
    else if (a==2)
        cout<<"貳";
    else if (a==3)
        cout<<"參";
    else if (a==4)
        cout<<"肆";
    else if (a==5)
        cout<<"伍";
    else if (a==6)
        cout<<"陸";
    else if (a==7)
        cout<<"柒";
    else if (a==8)
        cout<<"捌";
    else if (a==9)
        cout<<"玖";
}
