#include <iostream>
using namespace std;

int main()
{
    int a,b,c;
    while (cin>>a>>b>>c)
    {
        int ans=0;
        if (a+b+c>ans)
            ans=a+b+c;
        if (a*10+b+c>ans)
            ans=a*10+b+c;
        if (a+b*10+c>ans)
            ans=a+b*10+c;
        if (a*b*c>ans)
            ans=a*b*c;
        if ((a*10+b)*c>ans)
            ans=(a*10+b)*c;
        if (a*(b*10+c)>ans)
            ans=a*(b*10+c);
        if (a*b+c>ans)
            ans=a*b+c;
        if (a+b*c>ans)
            ans=a+b*c;
        cout<<ans<<endl;
    }
    return 0;
}
