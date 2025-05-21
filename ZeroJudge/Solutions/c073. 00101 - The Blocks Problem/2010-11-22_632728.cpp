#include <iostream>
using namespace std;

struct Node {int l,r;} a[50];
int search_top(int x)
{
    while (a[x].r!=-1)
        x=a[x].r;
    return x;
}
void print(int x)
{
    x=a[x].r;
    while (x!=-1)
    {
        printf(" %d",x);
        x=a[x].r;
    }
}
int main()
{
    string s1,s2;
    int n,b,c;
    while (cin>>n)
    {
        for (int i=0;i<n;i++)
        {
            a[n+i].r=i;
            a[i].l=n+i;
            a[i].r=-1;
        }
        while (cin>>s1)
        {
            if (s1=="quit")
                break;
            cin>>b>>s2>>c;
            int x=search_top(b),p=search_top(c);
            if (x==p)
                continue;
            if (s1=="move"&&a[b].r!=-1)
            {
                a[a[b].r].l=a[b].r+n;
                a[a[b].r+n].r=a[b].r;
                a[b].r=-1;
            }
            if (s2=="onto"&&a[c].r!=-1)
            {
                a[a[c].r].l=a[c].r+n;
                a[a[c].r+n].r=a[c].r;
                a[c].r=-1;
                p=search_top(c);
            }
            a[a[b].l].r=-1;
            a[b].l=p;
            a[p].r=b;
        }
        for (int i=0;i<n;i++)
        {
            printf("%d:",i);
            print(n+i);
            puts("");
        }
    }
    return 0;
}
