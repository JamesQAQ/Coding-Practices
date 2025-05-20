#include <iostream>
using namespace std;

int main()
{
    bool tenthousand=0;
    short ans[10001],temp[2][20001],at;
    ans[0]=1;
    memset(temp,0,sizeof(temp));
    temp[0][0]=1;
    temp[1][0]=1;
    for (int i=1;i<=10000;i++)
    {
        for (int j=1;j<2*i+1;j++)
        {
            temp[1][j]=temp[0][j]+temp[1][j-1];
            if (tenthousand)
                temp[1][j]%=10000;
            else if (temp[1][j]>=10000)
            {
                temp[1][j]%=10000;
                tenthousand=1;
                at=i;
            }
            temp[0][j]=temp[1][j];
        }
        ans[i]=temp[1][2*i];
    }
    int x;
    while (cin>>x)
    {
        if (x==0)
            break;
        if (x>=at)
            printf("%04d\n",ans[x]);
        else
            printf("%d\n",ans[x]);
    }
    return 0;
}
