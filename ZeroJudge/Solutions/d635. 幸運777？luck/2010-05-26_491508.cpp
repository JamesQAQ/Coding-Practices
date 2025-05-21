#include <iostream>
using namespace std;

int main()
{
    int a;
    while (cin>>a)
    {
        int s[3]={0};
        if (a<0)
        {
            cout<<-1<<endl;
            continue;
        }
        else if (a>=64)
        {
            s[0]=a/64;
            a%=64;
            if (a>=8)
            {
                s[1]=a/8;
                a%=8;
                s[2]=a;
            }
            else
                s[2]=a;
        }
        else if (a>=8)
        {
            s[1]=a/8;
            a%=8;
            s[2]=a;
        }
        else
            s[2]=a;
        if ((s[0]==0)&&(s[1]==0))
            cout<<s[2]<<endl;
        else if (s[0]==0)
            cout<<s[1]<<s[2]<<endl;
        else
            cout<<s[0]<<s[1]<<s[2]<<endl;
    }
    //system("pause");
    return 0;
}
