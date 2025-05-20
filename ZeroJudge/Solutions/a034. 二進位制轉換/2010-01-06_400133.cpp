#include <iostream>
using namespace std;

int main()
{
    int a;
    int i=0;
    string s[100];
    while (cin>>a)
    {
        if (a==0)
            cout<<0<<endl;
        else 
            {
                while (a>0)
                {
                    s[i]=a%2+48;
                    a /=2;
                    i++;
                }
                for (int b=i;b>=0;b--)
                    cout<<s[b];
                cout<<endl;
            }
        for (int c=0;c<=i;c++)
            s[c]='\0';
        i=0;
    }
    system ("pause");
    return 0;
}
