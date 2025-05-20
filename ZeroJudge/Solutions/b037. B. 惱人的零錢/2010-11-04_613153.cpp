#include <iostream>
using namespace std;

int main()
{
    int t,p,own,ans1,ans2,a[5],b[5],money[5]={1,5,10,20,50};
    while (cin>>t)
    {
        for (int k=0;k<t;k++)
        {
            cin>>p;
            own=0;
            for (int i=0;i<5;i++)
            {
                cin>>a[i];
                own+=money[i]*a[i];
            }
            for (int i=0;i<5;i++)
            {
                cin>>b[i];
                a[i]+=b[i];
            }
            own-=p;
            int sum1=own,sum2=own,temp=own/money[4];
            if (temp>a[4])
                temp=a[4];
            sum1-=temp*money[4];
            sum2-=(temp-1)*money[4];
            ans1=temp;
            ans2=temp-1;
            for (int i=3;i>=0;i--)
            {
                temp=sum1/money[i];
                if (temp>a[i])
                    temp=a[i];
                sum1-=temp*money[i];
                ans1+=temp;
                temp=sum2/money[i];
                if (temp>a[i])
                    temp=a[i];
                sum2-=temp*money[i];
                ans2+=temp;
            }
            cout<<((sum1==0)?ans1:ans2)<<endl;
        }
    }
    return 0;
}
