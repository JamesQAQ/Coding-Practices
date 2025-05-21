#include <iostream>
using namespace std;
#define MOD 1000000000

int number[30]={},num=1,sum[30]={},numd[30]={},d[30]={};
int test2(int n,int temp)
{
    if (n==0)
        return 0;
    int l=0,r=num,mid,ans;
    while (l<=r)
    {
        mid=(l+r)/2;
        if (numd[mid]>n) r=mid-1;
        else if (numd[mid]<n) l=mid+1;
        else break;
    }
    if (numd[mid]>n)
        mid--;
    ans=d[mid]+numd[mid]*temp;
    n-=numd[mid];
    ans+=test2(n,temp+1);
    ans%=MOD;
    return ans;
}
int test(int n)
{
    int l=0,r=num,mid,ans;
    while (l<=r)
    {
        mid=(l+r)/2;
        if (number[mid]>n) r=mid-1;
        else if (number[mid]<n) l=mid+1;
        else break;
    }
    if (number[mid]>n)
        mid--;
    ans=sum[mid];
    n-=number[mid];
    ans+=test2(n,0);
    ans%=MOD;
    return ans;
}
int main()
{
    int s=1,n;
    for (int i=2;i<150000000;i*=2)
    {
        number[num]=i-1;
        numd[num]=i/2;
        d[num]=s;
        sum[num]=(sum[num-1]+s)%MOD;
        s=(s*2+number[num-1]+1)%MOD;
        num++;
    }
    while (cin>>n)
        cout<<test(n)<<endl;
    return 0;
}
