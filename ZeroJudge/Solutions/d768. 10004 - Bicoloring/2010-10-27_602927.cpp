#include <iostream>
#include <deque>
using namespace std;

deque <int> Q;
bool finish;
int edge[200][200],num[200],n,color[200];
bool test(int x,int c)
{
    for (int i=0;i<num[x];i++)
        if (color[edge[x][i]]==c)
            return 0;
    return 1;
}
int main()
{
    int m;
    while (scanf("%d",&n))
    {
        if (n==0)
            break;
        scanf("%d",&m);
        int a,b;
        for (int i=0;i<n;i++)
        {
            num[i]=0;
            color[i]=0;
        }
        for (int i=0;i<m;i++)
        {
            scanf("%d",&a);
            scanf("%d",&b);
            edge[a][num[a]++]=b;
            edge[b][num[b]++]=a;
        }
        finish=1;
        Q.clear();
        int x=0;
        color[0]=1;
        Q.push_back(x);
        while (Q.empty()==0)
        {
            x=Q.front();
            Q.pop_front();
            for (int i=0;i<num[x];i++)
            {
                if (color[edge[x][i]])
                {
                    if (color[x]==color[edge[x][i]])
                    {
                        Q.clear();
                        finish=0;
                        break;
                    }
                }
                else
                {
                    color[edge[x][i]]=(color[x]==1)?2:1;
                    Q.push_back(edge[x][i]);
                }
            }
        }
        if (finish)
            cout<<"BICOLORABLE."<<endl;
        else
            cout<<"NOT BICOLORABLE."<<endl;
    }
    return 0;
}
