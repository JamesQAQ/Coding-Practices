#include <iostream>
using namespace std;

int pow_2[10]={1,2,4,8,16,32,64,128,256,512},a[512],sum[512],n;
void csum(bool b[],int x)
{
    for (int i=0;i<n;i++)
        if (b[i])
        {
            if (sum[x-pow_2[i]]==0)
            {
                b[i]=0;
                csum(b,x-pow_2[i]);
                b[i]=1;
            }
            if (sum[x-pow_2[i]]+a[x]>sum[x])
                sum[x]=sum[x-pow_2[i]]+a[x];
        }
    return;
}
int main()
{
    bool b[9];
    while (cin>>n)
    {
        if (n==0)
            break;
        for (int i=0;i<pow_2[n];i++)
        {
            cin>>a[i];
            sum[i]=0;
        }
        sum[0]=a[0];
        for (int i=0;i<n;i++)
            b[i]=1;
        csum(b,pow_2[n]-1);
        cout<<sum[pow_2[n]-1]<<endl;
    }
    return 0;
}
