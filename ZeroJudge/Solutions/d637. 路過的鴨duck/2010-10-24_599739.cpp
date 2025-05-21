#include <iostream>
using namespace std;

int n,c[101][10001],w[10001],v[10001];
int main()
{
    cin>>n;
    memset(c,0,sizeof(c));
    for (int i=1;i<=n;i++)
        cin>>v[i]>>w[i];
    for (int i=1;i<=100;i++)
        for (int j=1;j<=n;j++)
        {
            if (v[j]<=i)
            {
                if (w[j]+c[i-v[j]][j-1]>c[i][j-1])
                    c[i][j]=w[j]+c[i-v[j]][j-1];
                else
                    c[i][j]=c[i][j-1];
            }
            else
                c[i][j]=c[i][j-1];
        }
    cout<<c[100][n]<<endl;
    return 0;
}
