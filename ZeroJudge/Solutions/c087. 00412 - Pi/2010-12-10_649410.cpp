#include <iostream>
#include <cmath>
using namespace std;

int gcd(int m,int n)
{
    int temp;
    while (n!=0)
    {
        temp=n;
        n=m%n;
        m=temp;
    }
    return m;
}
int main()
{
    cout.setf(ios::fixed);
    cout.precision(6);
    int n,a[50];
    while (cin>>n)
    {
        if (n==0)
            break;
        double all=0,sum=0;
        for (int i=0;i<n;i++)
            cin>>a[i];
        for (int i=0;i<n-1;i++)
            for (int j=i+1;j<n;j++)
            {
                all++;
                if (gcd(max(a[i],a[j]),min(a[i],a[j]))==1)
                    sum++;
            }
        if (sum==0)
            cout<<"No estimate for this data set."<<endl;
        else
            cout<<sqrt(6*all/sum)<<endl;
    }
    return 0;
}
