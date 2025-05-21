#include <iostream>
#include <algorithm>
using namespace std;

struct Node {int m,a;string s;} data[100],dd[100];
int a[5],b[10][10],num,age,big[5];

bool cmp(Node i,Node j)
{
    if (i.m>j.m) return 1;
    if (i.m<j.m) return 0;
    if (i.s<j.s) return 1;
    return 0;
}
bool ccmp(int i,int j)
{
    return i>j;
}
int search(string s)
{
    for (int i=0;i<num;i++)
        if (s==data[i].s)
            return i;
    data[num].m=0;
    data[num].s=s;
    data[num].a=age;
    return num++;
}
int main()
{
    int n,m,p;
    char c;
    string s;
    while (cin>>n)
    {
        num=0;
        memset(a,0,sizeof(a));
        memset(big,0,sizeof(big));
        for (int i=0;i<n;i++)
        {
            cin>>s>>c>>c>>age>>m;
            p=search(s);
            a[c-'A']+=m;
            data[p].m+=m;            
        }
        int maxx=0;
        char ans;
        for (int i=0;i<5;i++)
            if (a[i]>maxx)
            {
                maxx=a[i];
                ans=i+'A';
            }
        cout<<ans<<endl;
        memset(b,0,sizeof(b));
        for (int i=0;i<num;i++)
            b[(data[i].m-1)/1000][(data[i].a-1)/10]++;
        for (int i=0;i<10;i++)
        {
            for (int j=0;j<10;j++)
                cout<<b[i][j]<<" ";
            cout<<endl;
        }
        for (int i=0;i<num;i++)
            if (data[i].m>big[4])
            {
                big[4]=data[i].m;
                stable_sort(big,big+5,ccmp);
            }
        int d=0;
        for (int i=0;i<num;i++)
            if (data[i].m>=big[4])
                dd[d++]=data[i];
        stable_sort(dd,dd+d,cmp);
        for (int i=0;i<d;i++)
            cout<<dd[i].s<<" "<<dd[i].m<<endl;
    }
    return 0;
}
