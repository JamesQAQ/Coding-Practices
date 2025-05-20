#include <iostream>
using namespace std;
int main()
{
    int a,b,m,n;
    while (cin>>a>>b)
    {
        if (a>b)
        {
            m=a;
            n=b;
        }
        else
        {
            n=a;
            m=b;
        }
        while (1)
        {
            m=m%n;
            if (m==0||n==0)
                goto the_end;
            n=n%m;
            if (m==0||n==0)
                goto the_end;
        }
        the_end:
        if (m==0)
            cout<<n<<endl;
        else
            cout<<m<<endl;
    }
    system("pause");
    return 0;
}
