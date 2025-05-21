#include <iostream>
#include <sstream>
using namespace std;

int a[10000064]={},c[10000000];
int sod(int x)
{
    int sum=0;
    while (x!=0)
    {
        sum+=x%10;
        x/=10;
    }
    return sum;
}
int main()
{
    c[0]=0;
    for (int i=1;i<=10000000;i++)
    {
        int p=i+sod(i);
        c[i]=c[i-1];
        if (a[p]==0)
            a[p]=i;
        if (a[i]==0)
            c[i]++;
    }
    string s;
    int n,t=0,num,b[2];
    cin>>n;
    getline(cin,s);
    while (n-->0)
    {
        getline(cin,s);
        num=0;
        stringstream ss(s);
        while (ss>>b[num])
            num++;
        printf("Case %d: ",++t);
        if (num==1)
        {
            if (a[b[0]]==0)
                puts("-1");
            else
                printf("%d\n",a[b[0]]);
        }
        else
        {
            int ans=c[b[1]]-c[b[0]];
            if (a[b[0]]==0)
                ans++;
            printf("%d\n",ans);
        }
    }
    return 0;
}
