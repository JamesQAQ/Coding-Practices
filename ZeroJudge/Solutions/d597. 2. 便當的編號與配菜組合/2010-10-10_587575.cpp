#include <iostream>
using namespace std;

int n,k,c[2000][10],num,b[10],a[10];

bool cmp(int j)
{
    for (int i=0;i<k;i++)
        if (c[j][i]!=a[i])
            return 0;
    return 1;
}
void dfs(int d,int x)
{
    if (x==k)
    {
        for (int i=0;i<k;i++)
            c[num][i]=b[i];
        num++;
        return;
    }
    for (int i=d+1;i<=n;i++)
    {
        b[x]=i;
        dfs(i,x+1);
    }
}
int main()
{
    while(cin>>n>>k){
    int i;
    for (i=0;i<k;i++)
        cin>>a[i];
    num=0;
    dfs(0,0);
    for (i=0;i<num;i++)
        if (cmp(i))
        {
            cout<<++i<<endl;
            break;
        }
    if (i!=num)
    {
        cout<<c[i][0];
        for (int j=1;j<k;j++)
            cout<<" "<<c[i][j];
        cout<<endl;
    }
    else
        cout<<"no next combination"<<endl;
    }
    return 0;
}
