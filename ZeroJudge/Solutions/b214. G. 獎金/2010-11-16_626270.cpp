#include <iostream>
using namespace std;

int main()
{
    int a,n,ans1,ans2,sum;
    while (cin>>n)
    {
        if (n==0)
            break;
        ans1=0;
        sum=0;
        ans2=0;
        for (int i=1;i<=n;i++)
        {
            cin>>a;
            a-=1000;
            if (sum<0)
                sum=a;
            else
                sum+=a;
            if (sum>ans1)
                ans1=sum;
            if (a>ans2)
                ans2=a;
        }
        cout<<ans1<<" "<<ans2<<endl;
    }
    return 0;
}
