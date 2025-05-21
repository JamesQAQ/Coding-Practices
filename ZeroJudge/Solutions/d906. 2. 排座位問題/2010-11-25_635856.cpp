#include <iostream>
#include <algorithm>
using namespace std;

char name[6];
int no[6],h[6],m,n,t[6];
bool cmp(int i,int j)
{
    if (m%2==0)
    {
        if (h[i]<h[j]) return 1;
        if (h[i]>h[j]) return 0;
    }
    if (no[i]<no[j]) return 1;
    return 0;
}
int main()
{
    while (cin>>m)
    {
        cin>>n;
        for (int i=0;i<6;i++)
        {
            cin>>name[i]>>no[i]>>h[i];
            t[i]=i;
        }
        stable_sort(t,t+6,cmp);
        if (n>2)
            cout<<name[t[8-n]]<<endl;
        else
            cout<<name[t[2-n]]<<endl;
    }
    return 0;
}
