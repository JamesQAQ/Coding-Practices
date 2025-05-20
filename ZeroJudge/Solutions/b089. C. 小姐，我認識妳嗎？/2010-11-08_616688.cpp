#include <iostream>
using namespace std;

int m,n,wrong[100],act[500][3],t[500],sum,solve;
bool ac[100];
int main()
{
    while (cin>>m>>n)
    {
        if (m==0&&n==0)
            break;
        for (int i=0;i<n;i++)
            cin>>act[i][0]>>act[i][1]>>act[i][2];
        for (int i=0;i<m;i++)
        {
            ac[i]=0;
            wrong[i]=0;
        }
        sum=0;
        solve=0;
        for (int i=0;i<n;i++)
            if (!ac[act[i][1]-1])
            {
                if (act[i][2])
                {
                    ac[act[i][1]-1]=1;
                    sum+=act[i][0]+wrong[act[i][1]-1]*20;
                    solve++;
                }
                else
                    wrong[act[i][1]-1]++;
            }
        cout<<sum<<" "<<solve<<endl;
    }
    return 0;
}
