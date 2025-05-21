#include <iostream>
using namespace std;

int a,b,c[1000000],d,e,r;
bool repeat()
{
    for (int i=0;i<d;i++)
        if (c[i]==e)
            return 1;
    return 0;
}
int main()
{
    while (cin>>a>>b)
    {
        if (a==0)
            cout<<"0"<<endl;
        else if (a==1)
            cout<<"1"<<endl;
        else if (a==-1)
        {
            if (b%2)
                cout<<"-1"<<endl;
            else
                cout<<"1"<<endl;
        }
        else
        {
            a%=10007;
            d=1;
            c[0]=a;
            e=a;
            r=0;
            for (int i=1;i<b;i++)
            {
                e=e*a%10007;
                if (repeat())
                {
                    r=1;
                    break;
                }
                c[d++]=e;
            }
            if (r==0)
                cout<<e<<endl;
            else
            {
                int ans=b%d;
                if (ans==0)
                    ans=d;
                cout<<c[ans-1]<<endl;
            }
        }
    }
    return 0;
}
