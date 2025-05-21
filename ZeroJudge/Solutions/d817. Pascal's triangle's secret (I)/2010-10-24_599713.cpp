#include <iostream>
using namespace std;

int a[5001][320];
int main()
{
    memset(a,0,sizeof(a));
    a[0][0]=1;
    for (int i=1;i<5001;i++)
    {
        for (int j=0;j<320;j++)
        {
            a[i][j]+=a[i-1][j]*2;
            if (a[i][j]>=100000)
            {
                a[i][j+1]+=a[i][j]/100000;
                a[i][j]%=100000;
            }
        }
    }
    int n;
    while (cin>>n)
    {
        int d;
        for (d=319;d>=0;d--)
            if (a[n][d]!=0)
            {
                printf("%d",a[n][d]);
                d--;
                break;
            }
        for (;d>=0;d--)
            printf("%05d",a[n][d]);
        printf("\n");
    }
    return 0;
}
