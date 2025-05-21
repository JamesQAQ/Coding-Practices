#include <iostream>
using namespace std;

int main()
{
    int a=1,b=1,k,n,m;
    while (cin>>k)
    {
        while ((a<=k)&&(b<=k))
        {
            if (a>b)
            {
                n=a;
                m=b;
                b+=a;
            }
            else
            {
                n=b;
                m=a;
                a+=b;
            }
        }
        cout<<m<<" "<<n<<endl;
        a=1;
        b=1;
    }
    //system ("pause");
    return 0;
}
