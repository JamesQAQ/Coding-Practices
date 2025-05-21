#include <iostream>
using namespace std;

int main()
{
    int a,b,r[1500],n[1500],num;
    while (cin>>a>>b)
    {
        num=0;
        if (a==0&&b==0)
            break;
        int d=-1,ans;
        while (a!=0)
        {
            r[num]=a;
            a*=10;
            n[num]=a/b;
            a%=b;
            num++;
            for (int i=0;i<num;i++)
                if (a==r[i])
                {
                    d=num;
                    ans=num-i;
                }
            if (d!=-1)
                break;
        }
        int sum=1;
        cout<<".";
        int limit=(d==-1)?num:d;
        for (int i=0;i<limit;i++)
        {
            if (sum%50==0)
                cout<<endl;
            cout<<n[i];
            sum++;            
        }
        cout<<endl;
        if (d!=-1)
            cout<<"The last "<<ans<<" digits repeat forever."<<endl;
        else
            cout<<"This expansion terminates."<<endl;
    }
    return 0;
}
