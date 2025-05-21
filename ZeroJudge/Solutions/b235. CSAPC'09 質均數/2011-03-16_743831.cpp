#include <iostream>
using namespace std;

bool p[7000]={};
int prime[7000],pnum=0,k,a[3],num[450];
int main()
{
    for (int i=3;i<7000;i+=2)
        p[i]=1;
    for (int i=3;i<7000;i+=2)
        if (p[i])
        {
            prime[pnum++]=i;
            for (int j=i*3;j<7000;j+=2*i)
                p[j]=0;
        }
    int ans=0;
    cin>>k;
    for (int i=0;i<k;i++)
    {
        cin>>a[i];
        ans=max(ans,a[i]);
    }
    int at=0,sum=0;
    while (sum<ans)
    {
        for (int i=0;i<pnum;i++)
        {
            if (prime[i]>=prime[at])
                break;
            if (p[prime[at]*2-prime[i]])
            {
                num[sum++]=prime[at];
                break;
            }
        }
        at++;
    }
    for (int i=0;i<k;i++)
        cout<<num[a[i]-1]<<endl;
    //system("pause");
    return 0;
}
