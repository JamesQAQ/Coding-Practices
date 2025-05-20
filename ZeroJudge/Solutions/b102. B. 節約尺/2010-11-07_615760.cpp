#include <iostream>
using namespace std;

bool repeat(int n,int a[])
{
    for (int i=1;i<n;i++)
        if (a[i]!=a[i-1])
            return 0;
    return 1;
}
bool check(int sum,bool ok[])
{
    for (int i=1;i<=sum;i++)
        if (!ok[i])
            return 0;
    return 1;
}
int main()
{
    int n,sum,a[20];
    bool ok[400];
    while (cin>>n)
    {
        if (n==0)
            break;
        sum=0;
        for (int i=0;i<n;i++)
        {
            cin>>a[i];
            sum+=a[i];
        }
        if (repeat(n,a))
        {
            cout<<"NO"<<endl;
            continue;
        }
        for (int i=0;i<=sum;i++)
            ok[i]=0;
        for (int i=0;i<n;i++)
            for (int j=i;j<n;j++)
            {
                int s=0;
                for (int k=i;k<=j;k++)
                    s+=a[k];
                ok[s]=1;
            }
        if (check(sum,ok))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
