#include <iostream>
using namespace std;

short s[100000][5],len,a[5],b[5];
int num;
void dfs(int x,int d)
{
    if (d==len)
    {
        for (int i=0;i<len;i++)
            s[num][i]=b[i];
        num++;
        return;
    }
    for (int i=x+1;i<=26;i++)
    {
        b[d]=i;
        dfs(i,d+1);
    }
}
bool ok()
{
    for (int i=0;i<4;i++)
    {
        if (a[i+1]==0)
            return 1;
        if (a[i]>=a[i+1])
            return 0;
    }
    return 1;
}
int bigsmall(int x)
{
    for (int i=4;i>=0;i--)
    {
        if (s[x][i]!=0&&a[i]!=0)
            break;
        if (s[x][i]==0&&a[i]!=0)
            return 2;
        if (a[i]==0&&s[x][i]!=0)
            return 0;
    }
    for (int i=0;i<5;i++)
    {
        if (s[x][i]<a[i]) return 2;
        if (s[x][i]>a[i]) return 0;
    }
    return 1;
}
int search(int l,int r)
{
    while (l<=r)
    {
        int mid=(l+r)/2;
        int d=bigsmall(mid);
        if (d==0) r=mid-1;
        else if (d==2) l=mid+1;
        else return mid;
    }
}
int main()
{
    memset(s,0,sizeof(s));
    num=0;
    for (len=1;len<6;len++)
        dfs(0,0);
    string s;
    while (cin>>s)
    {
        memset(a,0,sizeof(a));
        int len=s.length();
        for (int i=0;i<len;i++)
            a[i]=s[i]-'a'+1;
        if (ok())
            cout<<search(0,83681)+1<<endl;
        else
            cout<<"0"<<endl;
    }
    return 0;
}
