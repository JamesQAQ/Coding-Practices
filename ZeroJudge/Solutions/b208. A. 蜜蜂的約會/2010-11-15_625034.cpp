#include <iostream>
using namespace std;

int main()
{
    int at[100001],temp,n,len[100000],ans;
    while (cin>>n)
    {
        for (int i=0;i<n;i++)
        {
            cin>>temp;
            at[temp]=i;
        }

        ans=1;
        cin>>temp;
        len[0]=at[temp];
        for (int i=1;i<n;i++)
        {
            cin>>temp;
            temp=at[temp];
            if (temp>len[ans-1])
                len[ans++]=temp;
            else
            {
                int l=0,r=ans,mid;
                while (l<=r)
                {
                    mid=(l+r)/2;
                    if (temp>len[mid])
                        l=mid+1;
                    else if (temp<len[mid])
                        r=mid-1;
                    else
                        break;
                }
                if (temp<len[mid])
                    len[mid]=temp;
                else
                    len[mid+1]=temp;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
