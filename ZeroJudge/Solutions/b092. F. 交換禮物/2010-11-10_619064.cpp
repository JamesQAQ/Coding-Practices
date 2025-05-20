#include <iostream>
#include <algorithm>
using namespace std;

int n,sum,d,m[1000];
bool cmp(int i,int j)
{
    return i>j;
}
bool change()
{
    for (int i=0;i<n-1;i++)
    {
        stable_sort(m+i,m+n,cmp);
        if (m[i]==0)
            return 1;
        for (int j=0;j<m[i];j++)
        {
            if (m[i+j+1]==0)
                return 0;
            m[i+j+1]--;
        }
        m[i]=0;
    }
    return 1;
}
int main()
{
    while (scanf("%d",&n))
    {
        if (n==0)
            break;
        sum=0;
        d=0;
        for (int i=0;i<n;i++)
        {
            scanf("%d",&m[i]);
            sum+=m[i];
            if (m[i]>d)
                d=m[i];
        }
        if (d>n-1)
            puts("no");
        else if (sum%2)
            puts("no");
        else if (change())
            puts("yes");
        else
            puts("no");
    }
    return 0;
}
