#include <iostream>
#include <algorithm>
using namespace std;

int a[4]={2,3,5,7},h[5842],num=0;
string s[10];

void dfs(long long x,int d)
{
    if (num==5842)
        return;
    h[num++]=x;
    for (int i=d;i<4;i++)
        if (x*a[i]<=2000000000)
            dfs(x*a[i],i);
}
int main()
{
    s[0]="th";
    s[1]="st";
    s[2]="nd";
    s[3]="rd";
    for (int i=4;i<10;i++)
        s[i]="th";
    dfs(1,0);
    stable_sort(h,h+5842);
    int n;
    while (cin>>n)
    {
        if (n==0)
            break;
        cout<<"The "<<n;
        cout<<((n%100==11||n%100==12||n%100==13)?"th":s[n%10]);
        cout<<" humble number is "<<h[n-1]<<".\n";
    }
    return 0;
}
