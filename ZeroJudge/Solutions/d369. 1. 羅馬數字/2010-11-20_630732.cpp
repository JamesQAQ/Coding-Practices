#include <iostream>
using namespace std;

int main()
{
    int n,temp,v[90],len;
    string a,num[4][9]={{"M","MM","MMM"},
                        {"C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
                        {"X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
                        {"I","II","III","IV","V","VI","VII","VIII","IX"}};
    v['I']=1;
    v['V']=5;
    v['X']=10;
    v['L']=50;
    v['C']=100;
    v['D']=500;
    v['M']=1000;
    while (cin>>n)
        while (n-->0)
        {
            cin>>temp>>a;
            len=a.length();
            if (temp==1)
            {
                int sum=v[a[len-1]];
                for (int i=len-2;i>=0;i--)
                    sum+=(v[a[i]]>=v[a[i+1]])?v[a[i]]:-v[a[i]];
                cout<<sum<<endl;
            }
            else
            {
                int d=4-len;
                for (int i=0;i<len;i++)
                    if (a[i]-49>=0)
                        cout<<num[i+d][a[i]-49];
                cout<<endl;
            }
        }
    return 0;
}
