#include <iostream>
using namespace std;

int roman_math[7]={1,5,10,50,100,500,1000};
char roman_word[7]={'I','V','X','L','C','D','M'};
int load(string s);
int main()
{
    int c,d,e,f=0;
    string a,b;
    while (cin>>a)
    {
        if (a[0]=='#')
            break;
        cin>>b;
        c=load(a);
        d=load(b);
        e=(c>d)?c-d:d-c;
        if (e>1000)
        {
            f=e/1000;
            e%=1000;
            if (f==3)
                cout<<"MMM";
            else if (f==2)
                cout<<"MM";
            else
                cout<<"M";
        }
        if (e>100)
        {
            f=e/100;
            e%=100;
            if (f==9)
                cout<<"CM";
            else if (f==8)
                cout<<"DCCC";
            else if (f==7)
                cout<<"DCC";
            else if (f==6)
                cout<<"DC";
            else if (f==5)
                cout<<"D";
            else if (f==4)
                cout<<"CD";
            else if (f==3)
                cout<<"CCC";
            else if (f==2)
                cout<<"CC";
            else
                cout<<"C";
        }
        if (e>10)
        {
            f=e/10;
            e%=10;
            if (f==9)
                cout<<"XC";
            else if (f==8)
                cout<<"LXXX";
            else if (f==7)
                cout<<"LXX";
            else if (f==6)
                cout<<"LX";
            else if (f==5)
                cout<<"L";
            else if (f==4)
                cout<<"XL";
            else if (f==3)
                cout<<"XXX";
            else if (f==2)
                cout<<"XX";
            else
                cout<<"X";
        }
        if ((e==0)&&(f==0))
            cout<<"ZERO"<<endl;
        else if (e==9)
            cout<<"IX"<<endl;
        else if (e==8)
            cout<<"VIII"<<endl;
        else if (e==7)
            cout<<"VII"<<endl;
        else if (e==6)
            cout<<"VI"<<endl;
        else if (e==5)
            cout<<"V"<<endl;
        else if (e==4)
            cout<<"IV"<<endl;
        else if (e==3)
            cout<<"III"<<endl;
        else if (e==2)
            cout<<"II"<<endl;
        else if (e==1)
            cout<<"I"<<endl;
        else
            cout<<endl;
        f=0;
    }
    //system("pause");
    return 0;
}

int load(string s)
{
    int n=s.length();
    int sum=0,d;
    for (int i=0;i<n;i++)
    {
        if (i<n-1)
        {
            for (int ii=0;ii<7;ii++)
            {
                if (s[i+1]==roman_word[ii])
                    d=ii;
            }
        }
        else
            d=0;
        for (int ii=0;ii<7;ii++)
        {
            if (s[i]==roman_word[ii])
            {
                if (ii<d)
                    sum-=roman_math[ii];
                else
                    sum+=roman_math[ii];
            }
        }
    }
    return sum;
}
