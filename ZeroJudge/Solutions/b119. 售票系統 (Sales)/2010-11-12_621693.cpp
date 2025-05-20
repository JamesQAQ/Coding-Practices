#include <iostream>
using namespace std;

int main()
{
    int s,t,n,sum,temp,people;
    double p[4],ans;
    cout.setf(ios::fixed);
    cout.precision(0);
    while (cin>>s)
    {
        cin>>t>>n;
        sum=0;
        people=(int)t*0.2;
        for (int i=0;i<n;i++)
        {
            cin>>temp;
            sum+=temp;
        }
        ans=0;
        for (double i=0.7;i<1;i+=0.1)
        {
            if (sum>=people)
            {
                ans+=people*s*i;
                sum-=people;
            }
            else
            {
                ans+=sum*s*i;
                sum=0;
                break;
            }
        }
        ans+=sum*s;
        cout<<ans-s*t*0.3<<endl;
    }
    return 0;
}
