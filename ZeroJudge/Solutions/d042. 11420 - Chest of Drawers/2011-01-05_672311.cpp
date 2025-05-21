#include <iostream>
using namespace std;

int main()
{
    long long n,s,u[66][66]={},l[66][67]={};
    u[1][0]=1;
    l[1][1]=1;
    for (int i=2;i<=65;i++)
        for (int j=0;j<66;j++)
        {
            u[i][j]=u[i-1][j]+l[i-1][j+1];
            l[i][j+1]=u[i-1][j]+l[i-1][j];
        }
    while (cin>>n>>s)
    {
        if (n<0&&s<0)
            break;
        cout<<u[n][s]+l[n][s]<<endl;
    }
    return 0;
}
