#include <iostream>
using namespace std;

struct Node {int l,r;string s;} tree[26];
int num;
int search(char c)
{
    for (int i=0;i<num;i++)
        for (int j=0;j<tree[i].s.length();j++)
            if (c==tree[i].s[j])
                return i;
}
void dfs(int x)
{
    if (tree[x].l!=-1)
        dfs(tree[x].l);
    if (tree[x].r!=-1)
        dfs(tree[x].r);
    cout<<tree[x].s;
}
int main()
{
    string a,b,c,d;
    int p,at,len;
    while (cin>>a>>b)
    {
        len=a.length();
        num=1;
        tree[0].s=b;
        for (int i=0;i<len;i++)
        {
            at=search(a[i]);
            p=tree[at].s.find(a[i]);
            c=tree[at].s.substr(0,p);
            d=tree[at].s.substr(p+1,tree[at].s.length()-p);
            tree[at].s=tree[at].s.substr(p,1);
            if (c.length()>0)
            {
                tree[at].l=num;
                tree[num++].s=c;
            }
            else
                tree[at].l=-1;
            if (d.length()>0)
            {
                tree[at].r=num;
                tree[num++].s=d;
            }
            else
                tree[at].r=-1;
        }
        dfs(0);
        cout<<endl;
    }
    return 0;
}
