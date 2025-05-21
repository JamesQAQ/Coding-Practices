#include <iostream>
#include <sstream>
using namespace std;

struct Node {int x,l,r,n;} tree[1000];
int num=1;
void newnode(int x)
{
    int at=0;
    while (1)
    {
        if (x>tree[at].x)
        {
            if (tree[at].r==-1)
            {
                tree[at].r=num;
                tree[num].n=0;
                tree[num].x=x;
                tree[num].l=tree[num].r=-1;
                at=num++;
                break;
            }
            else
                at=tree[at].r;
        }
        else if (x<tree[at].x)
        {
            if (tree[at].l==-1)
            {
                tree[at].l=num;
                tree[num].n=0;
                tree[num].x=x;
                tree[num].l=tree[num].r=-1;
                at=num++;
                break;
            }
            else
                at=tree[at].l;
        }
        else
            break;
    }
    tree[at].n++;    
}
int main()
{
    string s;
    getline(cin,s);
    stringstream ss(s);
    int temp;
    ss>>temp;
    tree[0].x=temp;
    tree[0].l=tree[0].r=-1;
    tree[0].n=1;
    while (ss>>temp)
        newnode(temp);
    for (int i=0;i<num;i++)
        if (tree[i].n==2)
        {
            cout<<tree[i].x<<endl;
            break;
        }
    //system("pause");
    return 0;
}
