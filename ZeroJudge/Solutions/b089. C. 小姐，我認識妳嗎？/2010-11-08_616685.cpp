#include <iostream>
#include <algorithm>
using namespace std;

int m,n,wrong[100],act[500][3],t[500],sum,solve;
bool ac[100];
bool cmp(int i,int j)
{
    return act[i][0]<act[j][0];
}
int main()
{
    while (cin>>m>>n)
    {
        if (m==0&&n==0)
            break;
        for (int i=0;i<n;i++)
        {
            cin>>act[i][0]>>act[i][1]>>act[i][2];
            t[i]=i;
        }
        stable_sort(t,t+n,cmp);
        for (int i=0;i<m;i++)
        {
            ac[i]=0;
            wrong[i]=0;
        }
        sum=0;
        solve=0;
        for (int i=0;i<n;i++)
            if (!ac[act[t[i]][1]-1])
            {
                if (act[t[i]][2])
                {
                    ac[act[t[i]][1]-1]=1;
                    sum+=act[t[i]][0]+wrong[act[t[i]][1]-1]*20;
                    solve++;
                }
                else
                    wrong[act[t[i]][1]-1]++;
            }
        cout<<sum<<" "<<solve<<endl;
    }
    return 0;
}
