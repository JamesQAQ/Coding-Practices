#include <iostream>
using namespace std;

bool p[10000001]={};
int prime[40000]={2},pnum=1;
bool test_prime(int x)
{
    if (x<=10000000)
        return p[x];
    else
    {
        for (int i=0;i<pnum;i++)
            if (x%prime[i]==0)
                return 0;
        return 1;
    }
}
int main()
{
    p[2]=1;
    for (int i=3;i<10000000;i+=2)
        p[i]=1;
    for (int i=3;i<=46341;i++)
        if (p[i])
        {
            prime[pnum++]=i;
            for (int j=i*3;j<10000000;j+=2*i)
                p[j]=0;
        }
    int n;
    while (cin>>n)
    {
        if (n==0)
            break;
        cout<<!test_prime(n)<<endl;
    }
    return 0;
}
