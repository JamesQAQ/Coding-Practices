#include <iostream>
using namespace std;

int main()
{
    int a[51][3][20]={},n,d;
    a[0][0][0]=1;
    a[0][2][0]=1;
    for (int i=1;i<=50;i++)
    {
        for (int j=0;j<20;j++)
        {
            a[i][0][j]+=a[i-1][0][j]+a[i-1][1][j];
            if (a[i][0][j]>=10)
            {
                a[i][0][j+1]++;
                a[i][0][j]-=10;
            }
        }
        for (int j=0;j<20;j++)
        {
            a[i][1][j]+=a[i][0][j]+a[i-1][0][j];
            if (a[i][1][j]>=10)
            {
                a[i][1][j+1]++;
                a[i][1][j]-=10;
            }
        }
        for (int j=0;j<20;j++)
        {
            a[i][2][j]+=a[i][0][j]+a[i][1][j];
            if (a[i][2][j]>=10)
            {
                a[i][2][j+1]++;
                a[i][2][j]-=10;
            }
        }
    }
    while (cin>>n)
    {
        for (d=19;d>=0;d--)
            if (a[n][2][d]!=0)
                break;
        for (;d>=0;d--)
            cout<<a[n][2][d];
        cout<<endl;
    }
    return 0;
}
