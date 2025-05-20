#include <iostream>
#include <algorithm>
using namespace std;

int n,a[3],b[3],temp[3];
bool ok;
int main()
{
    while (cin>>n)
    {
        ok=1;
        for (int i=0;i<3;i++)
            cin>>a[i];
        for (int i=0;i<3;i++)
            cin>>b[i];
        if (n==0&&a[0]==0&&a[1]==0&&a[2]==0&&b[0]==0&&b[1]==0&&b[2]==0)
            break;
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                if(a[i]==b[j] || n-a[i]==b[j])
                {
                    a[i]=-1;
                    b[j]=-1;
                    break;
                }
        for(int i=0;i<3;i++)
            if(b[i]!=-1)
                ok=0;
        if (ok)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}
