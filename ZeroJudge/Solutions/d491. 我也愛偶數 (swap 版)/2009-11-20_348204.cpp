#include <iostream>
using namespace std;
int main()
{
    int a,b,m,n,sum=0;
    while (cin>>a>>b)
    {
        if (a>b)
            {
            m=a;
            n=b;
            }
        else
            {
            m=b;
            n=a;
            }
        if (m%2==1)
            m=m-1;
        if (n%2==1)
            n=n+1;
        for (int i=n;i<=m;i+=2)
            sum +=i;
        cout<<sum<<endl;
        sum=0;
        
    }
    system("pause");
    return 0;
}
