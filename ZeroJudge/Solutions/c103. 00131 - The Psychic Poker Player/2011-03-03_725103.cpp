#include <iostream>
#include <algorithm>
using namespace std;

struct Node{int n,c;}now[5],tu[5],o[5],d[5];
int point[13],color[4],rp[256],ans;

int test()
{
    bool straight=1;
    for (int i=1;i<5;i++)
    {
        if (i==1&&tu[i-1].n==0)
        {
            if (!(tu[i].n==9||tu[i].n==1))
            {
                straight=0;
                break;
            }
        }
        else if (tu[i].n!=tu[i-1].n+1)
        {
            straight=0;
            break;
        }
    }
    if (straight&&color[tu[0].c]==5)
        return 8;
    for (int i=0;i<5;i++)
        if (point[tu[i].n]==4)
            return 7;
    if (point[tu[0].n]==2||point[tu[0].n]==3)
    {   
        int temp=point[tu[point[tu[0].n]].n];
        if ((point[tu[0].n]==2&&temp==3)||(point[tu[0].n]==3&&temp==2))
            return 6;
    }
    if (color[tu[0].c]==5)
        return 5;
    if (straight)
        return 4;
    int tt[4]={};
    for (int i=0;i<5;i+=point[tu[i].n])
        tt[point[tu[i].n]]++;
    if (tt[3]>0)
        return 3;
    if (tt[2]==2)
        return 2;
    if (tt[2]>0)
        return 1;
    return 0;
}
bool cmp(Node i,Node j)
{
    return i.n<j.n;
}
void dfs(int x,int d)
{
    if (x==5)
    {
        memset(color,0,sizeof(color));
        memset(point,0,sizeof(point));
        for (int i=0;i<5;i++)
        {
            color[now[i].c]++;
            point[now[i].n]++;
            tu[i]=now[i];
        }
        stable_sort(tu,tu+5,cmp);
        ans=max(ans,test());
        return;
    }
    for (int i=d;i<5;i++)
    {
        now[x]=o[i];
        dfs(x+1,i+1);
    }
}
int main()
{
    string s[9]={"highest-card","one-pair","two-pairs","three-of-a-kind","straight","flush","full-house","four-of-a-kind","straight-flush"};
    rp['A']=0;
    rp['T']=9;
    rp['J']=10;
    rp['Q']=11;
    rp['K']=12;
    rp['C']=0;
    rp['D']=1;
    rp['H']=2;
    rp['S']=3;
    for (int i=1;i<9;i++)
        rp[i+'1']=i;
    char cc[5][2],dd[5][2];
    while (cin>>cc[0][0]>>cc[0][1])
    {
        o[0].n=rp[cc[0][0]];
        o[0].c=rp[cc[0][1]];
        for (int i=1;i<5;i++)
        {
            cin>>cc[i][0]>>cc[i][1];
            o[i].n=rp[cc[i][0]];
            o[i].c=rp[cc[i][1]];
        }
        for (int i=0;i<5;i++)
        {
            cin>>dd[i][0]>>dd[i][1];
            d[i].n=rp[dd[i][0]];
            d[i].c=rp[dd[i][1]];
        }
        ans=0;
        for (int i=0;i<=5;i++)
        {
            for (int j=0;j<i;j++)
                now[j]=d[j];
            dfs(i,0);
        }
        cout<<"Hand: ";
        for (int i=0;i<5;i++)
            cout<<cc[i][0]<<cc[i][1]<<" ";
        cout<<"Deck: ";
        for (int i=0;i<5;i++)
            cout<<dd[i][0]<<dd[i][1]<<" ";
        cout<<"Best hand: ";
        cout<<s[ans]<<endl;
    }
    return 0;
}
