#include <iostream>
using namespace std;

int gcd(int m,int n)
{
    if (m<n)
        swap(m,n);
    while (n!=0)
    {
        m%=n;
        swap(m,n);
    }
    return m;
}
int main()
{
    int lens1,lens2,cases,num1,num2;
    string s1,s2;
    cin>>cases;
    for (int t=1;t<=cases;t++)
    {
        cin>>s1>>s2;
        num1=num2=0;
        lens1=s1.length();
        lens2=s2.length();
        for (int i=0;i<lens1;i++)
            num1=num1*2+s1[i]-48;
        for (int i=0;i<lens2;i++)
            num2=num2*2+s2[i]-48;
        cout<<"Pair #"<<t<<": ";
        if (gcd(num1,num2)==1)
            cout<<"Love is not all you need!\n";
        else
            cout<<"All you need is love!\n";
    }
    return 0;
}
