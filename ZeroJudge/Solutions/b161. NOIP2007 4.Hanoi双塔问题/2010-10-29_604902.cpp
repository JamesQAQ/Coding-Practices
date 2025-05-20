#include <iostream>
using namespace std;
#define LEN 100

int a[201][LEN]={};
int main()
{
    a[1][0]=2;
    for (int i=2;i<=200;i++)
    {
        for (int j=0;j<2;j++)
            for (int k=0;k<LEN;k++)
                a[i][k]+=a[i-1][k];
        a[i][0]+=2;
        for (int j=0;j<LEN;j++)
            if (a[i][j]>=10)
            {
                a[i][j+1]+=a[i][j]/10;
                a[i][j]%=10;
            }
    }
    int x;
    while (cin>>x)
    {
        int i;
        for (i=LEN-1;i>=0;i--)
            if (a[x][i]!=0)
                break;
        for (;i>=0;i--)
            cout<<a[x][i];
        cout<<endl;
    }
    return 0;
}
