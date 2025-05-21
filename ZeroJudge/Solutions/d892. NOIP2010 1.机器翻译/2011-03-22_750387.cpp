#include <iostream>
using namespace std;

int main()
{
    int list[1002],n,m,num=0,temp,end=0,ans=0;
    bool use[1002]={};
    list[0]=-1;
    cin>>m>>n;
    for (int i=0;i<n;i++)
    {
        cin>>temp;
        temp++;
        if (!use[temp])
        {
            if (num<m)
            {
                list[end]=temp;
                list[temp]=-1;
                end=temp;
                use[temp]=1;
                ans++;
                num++;
            }
            else
            {
                use[list[0]]=0;
                list[0]=list[list[0]];
                list[end]=temp;
                list[temp]=-1;
                end=temp;
                use[temp]=1;
                ans++;
            }
        }
        int at=list[0];
    }
    cout<<ans<<endl;
    //system("pause");
    return 0;
}
