#include <iostream>
#include <cmath>
using namespace std;

struct Node{int h,n,b[300];} tree[300];
bool use[300],found,start=0;
string name[300];
int num=0,up,down;
int search(string s)
{
    for (int i=0;i<num;i++)
        if (s==name[i])
            return i;
    if (start)
        return -1;
    name[num]=s;
    tree[num].n=0;
    tree[num].h=-1;
    return num++;
}
void dfs(int now,int u,int d,int goal)
{
    //cout<<name[now]<<endl;
    if (now==goal)
    {
        found=1;
        up=u;
        down=d;
        return;
    }
    if (tree[now].h!=-1)
        if (!use[tree[now].h])
        {
            use[tree[now].h]=1;
            dfs(tree[now].h,u+1,d,goal);
            if (found)
                return;
        }
    for (int i=0;i<tree[now].n;i++)
        if (!use[tree[now].b[i]])
        {
            use[tree[now].b[i]]=1;
            dfs(tree[now].b[i],u,d+1,goal);
            if (found)
                return;
        }
}
int main()
{
    string a,b;
    int aa,bb;
    while (cin>>a>>b)
    {
        if (a=="no.child")
            break;
        aa=search(a);
        bb=search(b);
        tree[bb].b[tree[bb].n++]=aa;
        tree[aa].h=bb;
    }
    start=1;
    while (cin>>a>>b)
    {
        aa=search(a);
        bb=search(b);
        if (aa==-1||bb==-1)
        {
            cout<<"no relation"<<endl;
            continue;
        }
        for (int i=0;i<num;i++)
            use[i]=0;
        found=0;
        use[bb]=1;
        dfs(bb,0,0,aa);
        if (!found)
            cout<<"no relation"<<endl;
        else if (up==0)
        {
            for (int i=down;i>2;i--)
                cout<<"great ";
            if (down>1)
                cout<<"grand ";
            cout<<"child"<<endl;
        }
        else if (down==0)
        {
            for (int i=up;i>2;i--)
                cout<<"great ";
            if (up>1)
                cout<<"grand ";
            cout<<"parent"<<endl;
        }
        else
        {
            int n1=min(up,down)-1,n2=abs(up-down);
            if (n1==0&&n2==0)
            {
                cout<<"sibling"<<endl;
                continue;
            }
            cout<<n1<<" cousin";
            if (n2!=0)
                cout<<" removed "<<n2;
            cout<<endl;
        }
    }
    return 0;
}
