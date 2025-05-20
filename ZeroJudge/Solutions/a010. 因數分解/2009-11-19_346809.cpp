#include <iostream>
using namespace std;
int main()
{
    int x,i,r,m=1;
    while (cin>>x)
    {
        for (i=2;i<=x;i++)
        {
            if (x==1)
                cout<<x<<endl;
            else if (x%i==0)
            {
                cout<<i;
                x=x/i;
                r=x%i;
                while (r==0)
                {
                    x=x/i;
                    m++;
                    r=x%i;   
                }   
                if (m>1)
                    cout<<"^"<<m;
                m=1;
                if (x!=1)
                    cout<<" * ";
                else if (x==1)
                    goto the_end;
            }   
        }   
        the_end:
            cout<<endl;
    }
    system("pause");
    return 0;
}
