#include <iostream>
using namespace std;

long long a[10000][7];
int main()
{
    int n,cases,len[10000];
    cin>>cases;
    while (cases-->0)
    {
        cin>>n;
        for (int i=0;i<n;i++)
            cin>>len[i];
        for (int i=0;i<n;i++)
            for (int j=0;j<7;j++)
                a[i][j]=-1;
        a[0][0]=2*len[0];
        for (int i=0;i<n-1;i++)
        {
            for (int j=0;j<7;j++)
            {
                if (a[i][j]==-1)
                    continue;
                if (a[i+1][j]==-1||a[i][j]+5+2*len[i+1]<a[i+1][j])
                    a[i+1][j]=a[i][j]+5+2*len[i+1];
                if (j<6&&(a[i+1][j+1]==-1||a[i][j]+10+2*len[i+1]<a[i+1][j+1]))
                    a[i+1][j+1]=a[i][j]+10+2*len[i+1];
                if (j>=3&&(a[i+1][j-3]==-1||a[i][j]+5+len[i+1]<a[i+1][j-3]))
                    a[i+1][j-3]=a[i][j]+5+len[i+1];
                if (j<6&&j>=2&&(a[i+1][j-2]==-1||a[i][j]+10+len[i+1]<a[i+1][j-2]))
                    a[i+1][j-2]=a[i][j]+10+len[i+1];
            }
        }
        /*for (int i=0;i<n;i++)
        {
            for (int j=0;j<7;j++)
                cout<<a[i][j]<<" ";
            cout<<endl;
        }*/
        long long ans=a[n-1][0];
        for (int i=1;i<7;i++)
        {
            if (a[n-1][i]==-1)
                continue;
            ans=min(a[n-1][i],ans);
        }
        cout<<ans<<endl;
    }
    return 0;
}
