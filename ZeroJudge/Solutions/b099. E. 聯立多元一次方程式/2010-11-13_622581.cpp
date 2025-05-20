#include <iostream>
#include <cmath>
using namespace std;

int cases,n;
double temp,a[1000][1000];
bool ok[1000];

int big(int x)
{
    double maxx=0;
    int at;
    for (int i=0;i<n;i++)
        if (a[x][i]>maxx)
        {
            maxx=a[x][i];
            at=i;
        }
    double sum=0;
    for (int i=0;i<n;i++)
    {
        if (i==at)
            continue;
        sum+=a[x][i];
        if (sum>=maxx)
            return -1;
    }
    return at;
}
bool check()
{
    for (int i=0;i<n;i++)
    {
        int p=big(i);
        if (p!=-1)
        {
            if (!ok[p])
                ok[p]=1;
            else
                return 0;
        }
        else
            return 0;
    }
    return 1;
}
int main()
{
    while (cin>>cases)
        while (cases-->0)
        {
            cin>>n;
            for (int i=0;i<n;i++)
                for (int j=0;j<n;j++)
                {
                    cin>>temp;
                    a[i][j]=fabs(temp);
                }
            for (int i=0;i<n;i++)
                ok[i]=0;
            if (check())
                cout<<"yes"<<endl;
            else
                cout<<"no"<<endl;
        }
    return 0;
}
